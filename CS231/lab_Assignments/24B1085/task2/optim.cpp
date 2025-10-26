/*

This file contains implementationss for:
1. Outer product of 2 matrices
2. Convolution of 2 matrices
3. Wierd multiplication of a matrix

*/





#include "../common/matrix.hpp"
#include <cmath>
#include <immintrin.h>

matrix* transpose(matrix* a) {
    auto [r, c] = a->size();
    matrix* res = new matrix(c, r);
    for (uint64_t i = 0; i < r; i++) {
        for (uint64_t j = 0; j < c; j++) {
            *(res->element(j, i)) = *(a->element(i, j));
        }
    }
    return res;
}

matrix* outer(matrix *a, matrix *b) {
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    matrix *res = new matrix(r1 * r2, c1 * c2);
    // compute res
    

    for (auto i =0; i<r1; i++) {
        for (auto j =0; j<c1; j++) {
            __m256d a_val = _mm256_set1_pd(*a->element(i, j));
            for (auto p = 0; p<r2; p++) {
                uint64_t q = 0;
                for (; q+4<=c2; q+=4) {
                    __m256d bvec=_mm256_loadu_pd(b->element(p,q));
                    __m256d product = _mm256_mul_pd(a_val, bvec);
                    alignas(32) double tmp[4];
                    _mm256_store_pd(tmp,product);
                    *res->element(i*r2+p, j*c2+q)=tmp[0];
                    *res->element(i*r2+p, j*c2+q+1)=tmp[1];
                    *res->element(i*r2+p, j*c2+q+2)=tmp[2];
                    *res->element(i*r2+p, j*c2+q+3)=tmp[3];
                    
                }
                for (; q <c2; q++) {
                    *res->element(i*r2+p, j*c2+q)=*a->element(i,  j) * (*b->element(p,  q));
                }
            }

        }
    }
    return res;
}

matrix* convolve(matrix* a, matrix* b) {
    // output matrix dim must be same as a-> dim
    // and a->dim must be greater than b->dim
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    if (r1 < r2 || c1 < c2) {
        return nullptr; // Dimension mismatch   
    }
    if (r2 % 2 == 0 || c2 % 2 == 0) {
        return nullptr; // Kernel dimensions must be odd
    }
    matrix* res = new matrix(r1, c1);
    // compute res
    if (r1<r2 || c1<c2) return nullptr;
    if (r2%2 == 0 || c2%2 == 0) return nullptr;
    int r_2 = (r2-1)/2;
    int c_2 = (c2-1)/2;

    for (int i = r_2; i<r1-r_2; i++) {
        for (int j = c_2; j<c1-c_2; j++) {
            __m256d vsum = _mm256_setzero_pd();
            double sum = 0.0;

            for (int k = -r_2;  k<=r_2; k++) {
                int l = -c_2;
                for (; l <= c_2-3; l+=4) {
                    __m256d va=_mm256_loadu_pd(a->element(i+k,j+l));

                    __m256d vb=_mm256_loadu_pd(b->element(k + r_2, l + c_2));
                    __m256d product = _mm256_mul_pd(va, vb);
                    vsum = _mm256_add_pd(vsum, product);
                }
                

                for (; l <= c_2; l++) {
                    sum += (*a->element(i + k, j + l)) *
                           (*b->element(k + r_2, l + c_2));
                }

            }
                alignas(32) double tmp[4];
                _mm256_store_pd(tmp, vsum);
                sum += tmp[0] + tmp[1] + tmp[2] + tmp[3];
            *res->element(i,  j) = sum;

        }
    }

    return res;
}

matrix* weirdMul(matrix* a, matrix* b) {
    auto [r1, c1] = a->size();
    auto [r2, c2] = b->size();
    if (c1 != r2) {
        return nullptr; // Dimension mismatch
    }
    matrix* res = new matrix(r1, c2);
    // compute res
    matrix*b_transpose = transpose(b);

    __m256d thershold = _mm256_set1_pd(0.5);
    __m256d one = _mm256_set1_pd(1.0);

    for (uint64_t i = 0; i < r1; i++) {
        for (uint64_t j = 0; j < c2; j++) {
            __m256d vsum = _mm256_setzero_pd();
            double sum = 0.0;

            uint64_t k = 0;
            for (; k + 4 <= c1; k += 4) {
                // __m256d va = _mm256_set_pd(
                //     *a->element(i, k + 3),
                //     *a->element(i, k + 2),
                //     *a->element(i, k + 1),
                //     *a->element(i, k)
                // );
                __m256d va = _mm256_loadu_pd(a->element( i, k));
                // __m256d vb = _mm256_set_pd(
                //     *b_transpose->element(j, k + 3),
                //     *b_transpose->element(j, k + 2),
                //     *b_transpose->element(j, k + 1),
                //     *b_transpose->element(j, k)
                // );
                __m256d vb = _mm256_loadu_pd(b_transpose->element(j, k));
                __m256d cond = _mm256_cmp_pd(va, thershold, _CMP_GT_OS);
                __m256d pos = _mm256_mul_pd(va, vb);
                __m256d neg = _mm256_mul_pd(_mm256_sub_pd(one, va), vb);
                neg = _mm256_sub_pd(_mm256_setzero_pd(), neg);
                __m256d blend = _mm256_blendv_pd(neg, pos, cond);
                vsum = _mm256_add_pd(vsum, blend);
            }

            alignas(32) double tmp[4];
            _mm256_store_pd(tmp, vsum);
            sum += tmp[0] + tmp[1] + tmp[2] + tmp[3];

            for (; k < c1; k++) {
                double aval = *a->element(i, k);
                double bval = *b_transpose->element(j, k);
                sum += (aval > 0.5 ? aval * bval : -(1 - aval) * bval);
            }

            *res->element(i, j) = sum;
        }
    }

    delete b_transpose;

    return res;
}
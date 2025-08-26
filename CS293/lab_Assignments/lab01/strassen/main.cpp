#include "common.h"
#include "strassen.h"


Matrix generateRandomMatrix(int N) {
    Matrix mat(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            mat[i][j] = rand() % 21 - 10;
    return mat;
}

template<typename Func>
long long measureTime(Func f) {
    auto start = high_resolution_clock::now();
    f();
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}
int main() {
    srand(time(0));
    vector<int> sizes = {64, 128, 256, 512, 1024};
    vector<int> thresholds = {2, 4, 8, 16, 32, 64, 128};

    for (int threshold : thresholds) {
      for (int N : sizes) {
        Matrix A = generateRandomMatrix(N);
        Matrix B = generateRandomMatrix(N);

        Matrix C1, C2;

        long long t2 = measureTime([&]() {
          C2 = strassenMultiply(A, B, threshold);
        });

        long long t1 = measureTime([&]() {
            C1 = naiveMultiply(A, B);
        });

       

        cout << "Threshold = " << threshold << " N = " << N << ": Naive = " << t1 << "ms, Strassen = " << t2 << "ms";

        if (!equal(C1, C2))
            cout << " Mismatch!\n";
        else {
            cout << "\n";
        }
      }
    }
    return 0;
}

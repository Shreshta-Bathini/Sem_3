#include "common.h"

// Add two matrices
Matrix add(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  // TODO
  return C;
}

// Subtract two matrices
Matrix subtract(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  // TODO
  return C;
}

// Naive O(N^3) matrix multiplication
Matrix naiveMultiply(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  // TODO
  return C;
}

// Strassen's matrix multiplication, use the reference for the algorithm
Matrix strassenMultiply(const Matrix &A, const Matrix &B, int threshold) {
  int n = A.size();
  Matrix C(n, vector<int>(n));
  // TODO
  return C;
}


bool equal(const Matrix &A, const Matrix &B) {
    /*
        Returns True if the input matrices are equal and false otherwise
    */
    // TODO
  return false; // Dummy return
}


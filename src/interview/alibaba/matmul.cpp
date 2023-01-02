// 评测题目:
// 用向量化函数实现一个矩阵乘
// 向量数据格式 float4 a;
// 访问向量中的一个元素 a[i], i >= 0 && i <=3
// 向量Load函数：float4 load(void* p)；
// 向量Store函数：void store(float4 a, void* p);
// 标量broadcat成向量函数: float4 bcast(float a);
// 向量乘加函数c+=a*b: madd(float4* a, float4* b, float4* c);
//   a = {2 2 2 2}
//   b = {3 3 3 3}
//   c = {1 1 1 1} -> {7 7 7 7}
// 矩阵乘法计算表达式：
//  for （int i = 0; i < M; ++i)
//    for (int j = 0; j < N; ++j)
//      for (int k = 0; k < K; ++k)
//        C[i, j] += A[i, k] * B[k, j]

// matmul（A<M * K * F32>, B<K * N * F32>, C<M * N * F32>）

#include <iostream>

#define A(i, j) A[i * K + j]
#define B(i, j) B[i * N + j]
#define C(i, j) C[i * N + j]

inline void add_dot_4x4(const float *A, const float *B, float *C,
                        const size_t K, const size_t N) {
  float4 c40 = load(&C(0, 0));
  float4 c41 = load(&C(1, 0));
  float4 c42 = load(&C(2, 0));
  float4 c43 = load(&C(3, 0));
  for (size_t k = 0; k < K; ++k) {
    float4 a40 = bcast(A(0, k));
    float4 b40 = load(&B(k, 0));
    madd(a40, b40, c40);

    float4 a41 = bcast(A(1, k));
    float4 b41 = load(&B(k, 0));
    madd(a41, b41, c41);

    float4 a42 = bcast(A(2, k));
    float4 b42 = load(&B(k, 0));
    madd(a42, b42, c42);

    float4 a43 = bcast(A(3, k));
    float4 b43 = load(&B(k, 0));
    madd(a43, b43, c43);
  }
  store(c40, &C(0, 0));
  store(c41, &C(1, 0));
  store(c42, &C(2, 0));
  store(c43, &C(3, 0));
}

void MatMul(float *A, float *B, float *C, size_t M, size_t K, size_t N) {
  for (int m = 0; m < M; m += 4) {
    for (int n = 0; n < N; n += 4) {
      add_dot_4x4(&A(m, 0), &BR(0, n), &C(m, n), K, N);
    }
  }
}

int main() {}
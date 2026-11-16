#include <iostream>
#include <vector>
#include <cmath>

void heavy_math(std::vector<float>& a, const std::vector<float>& b, const std::vector<float>& c) {
    size_t n = a.size();
    for (size_t i = 0; i < n; ++i) {
        a[i] = b[i] * c[i] + 1.5f;
    }
}

void run_benchmark(size_t n, int iterations) {
    std::vector<float> a(n, 0.0f);
    std::vector<float> b(n, 2.5f);
    std::vector<float> c(n, 4.0f);

    for (int iter = 0; iter < iterations; ++iter) {
        heavy_math(a, b, c);
    }

    std::cout << "Check result: " << a[n / 2] << std::endl;
}

int main() {
    const size_t N = 10'000'000;
    const int ITERATIONS = 300;
    run_benchmark(N, ITERATIONS);
    return 0;
}
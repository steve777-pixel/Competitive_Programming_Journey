#pragma once

constexpr long long MODULO = 1'000'000'007LL;

inline long long add(long long a, long long b) { return a + b; }

inline int gcd(int a, int b){
    if(b == 0) return a;

    return gcd(b, a % b);
}

inline long long factorialMod(int n){
    if(n < 0) return -1LL;
    if(n >= MODULO) return 0;

    long long a = 1;

    for(int i = 2; i <= n; i++){
        a = (a * i) % MODULO;
    }

    return a;
}

template <typename T>
inline T absoluteVal(T a){
    return (a >= 0) ? a : a * -1;
}

inline long long power(long long base, unsigned int exp) {
    long long result = 1;
    
    while (exp > 0) {
        if (exp & 1) {
            result *= base;
        }

        base *= base;

        exp >>= 1;
    }

    return result;
}

inline bool compareDouble(double a, double b){
    constexpr double EPSILON = 1e-9; // 0.000000001

    return absoluteVal(a - b) < EPSILON;
}

inline long long sumOfIntegersUptoN(int n){
    if(n <= 0) return 0;

    return static_cast<long long>(n) * (n + 1) / 2;
}

inline long long sumOfSquaresUptoN(int n){
    if(n <= 0) return 0;

    return static_cast<long long>(n) * (n + 1) * (2LL * n + 1) / 6;
}

inline long long sumOfFiniteGeometricSeries(int firstTerm, int ratio, int n){
    if(n <= 0 || ratio == 1) return 0LL;

    long long lastTerm = static_cast<long long>(firstTerm) * power(ratio, n - 1);

    return (lastTerm * ratio - firstTerm) / (ratio - 1);
}

inline long long sumOfInfiniteGeometricSeries(int firstTerm, double ratio){
    if(absoluteVal(ratio) >= 1.0) return 0LL;

    return static_cast<long long>(firstTerm) / (1.0 - ratio);
}
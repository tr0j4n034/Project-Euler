//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/14/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <bitset>

using namespace std;

const int MAX = 3500005;
const int SIEVE_SIZE = 15000000;
const long long OFFSET = 100000000000000LL;
const long long MODULO = 1234567891011LL;

int p0[SIEVE_SIZE];
int p[MAX];

//long long multiply(long long a, long long b, long long modulo) {
//    if (b == 0) return 0;
//    if (b & 1) return (a + multiply(a, b - 1, modulo)) % modulo;
//    else return multiply((a + a) % modulo, b >> 1, modulo);
//}
long long multiply(long long a, long long b, long long modulo) {
    long long q = (long double)a * (long double)b / (long double)modulo;
    long long result = a * b - q * modulo;
    return (result + (modulo << 2)) % modulo;
}

struct matrix{
    long long a[2][2];
    matrix() {
        
    }
};
matrix operator * (matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < 2; j ++) {
            c.a[i][j] = 0;
            for (int k = 0; k < 2; k ++) {
                c.a[i][j] = (c.a[i][j] + multiply(a.a[i][k], b.a[k][j], MODULO)) % MODULO;
            }
        }
    }
    return c;
}
matrix power(matrix a, long long p) {
    if (p == 1) {
        return a;
    }
    if (p & 1) {
        return power(a, p - 1) * a;
    }
    matrix half = power(a, p >> 1);
    return half * half;
}
long long getFibonacci(long long N) {
    matrix fib;
    fib.a[0][0] = 1;
    fib.a[0][1] = 1;
    fib.a[1][0] = 1;
    fib.a[1][1] = 0;
    matrix pw = power(fib, N);
    return pw.a[0][1];
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i * i < SIEVE_SIZE; i ++) {
        if (p0[i]) continue;
        for (int j = i * i; j < MAX; j += i) {
            p0[j] = 1;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; 1LL * i * i <= (OFFSET + MAX); i ++) {
        if (p0[i]) continue;
        for (long long j = (OFFSET % i == 0 ? OFFSET : OFFSET + i - OFFSET % i); j < OFFSET + MAX; j += i) {
            p[j - OFFSET] = 1;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long sum = 0;
    int primes = 0;
    for (int i = 0; i < MAX && primes < 100000; i ++) {
        if (p[i] == 0) {
            primes ++;
            sum = (sum + getFibonacci(OFFSET + i)) % MODULO;
        }
    }
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

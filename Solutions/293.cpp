//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/18/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int S = 40000;
const int UP = 1000000000;

int p[S];
vector<int> primes;
set<int> s;

bool isPrime(int N) {
    if (N < 2) return false;
    for (int i: primes) {
        if (N % i == 0) return false;
        if (i * i > N) break;
    }
    return true;
}
int getNextPrime(int N) {
    for (int j = N + 2; ; j ++) {
        if (isPrime(j)) return j - N;
    }
    return -1;
}
void generate(int N, int position) {
    if (N >= UP) {
        return;
    }
    if (N != 1) {
        s.insert(getNextPrime(N));
    }
    int M = N;
    for (int i = 0; ; i ++) {
        if (M > UP / primes[position]) {
            break;
        }
        M *= primes[position];
        generate(M, position + 1);
    }
}

int main() {
    for (int i = 2; i < S; i ++) {
        if (p[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < S; j += i) {
            p[j] = 1;
        }
    }
    generate(1, 0);
    
    long long result = 0;
    for (int i: s) {
        result += i;
    }
    cout << result << endl;
    
    return 0;
}

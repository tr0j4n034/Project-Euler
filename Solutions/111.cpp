//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/12/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000000;

int N;
int p[MAX], primes[MAX];

bool isPrime(long long N) {
    if (N < 2) return false;
    for (int i = 1; i <= ::N; i ++) {
        if (1LL * primes[i] * primes[i] > N) break;
        if (N % primes[i] == 0) return false;
    }
    return true;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        primes[++N] = i;
        for (int j = i + i; j < MAX; j += i) {
            p[j] = 1;
        }
    }
    int L = 10;
    long long sum = 0;
    for (int digit = 0; digit < 10; digit ++) {
        string number = "";
        for (int i = 0; i < L; i ++) {
            number += (char)(digit + '0');
        }
        int can = 0;
        for (int i = 0; i < L; i ++) {
            for (int j = 0; j < 10; j ++) {
                if (j == digit) continue;
                string current = number;
                current[i] = (char)(j + '0');
                if (current[0] == '0') continue;
                if (isPrime(stoll(current))) {
                    can = 1;
                    sum += stoll(current);
                }
            }
        }
        cerr << digit << " " << can << endl;
        if (can) continue;
        for (int i = 0; i < L; i ++) {
            for (int j = i + 1; j < L; j ++) {
                for (int k = 0; k < 10; k ++) {
                    if (k == digit) continue;
                    for (int q = 0; q < 10; q ++) {
                        if (q == digit) continue;
                        string current = number;
                        current[i] = (char)(k + '0');
                        current[j] = (char)(q + '0');
                        if (current[0] == '0') continue;
                        if (isPrime(stoll(current))) {
                            can = 1;
                            sum += stoll(current);
                        }
                    }
                }
            }
        }
        cout << "second chance for " << digit << " " << can << endl;
    }
    
    cout << sum << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

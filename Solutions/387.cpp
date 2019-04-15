//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/05/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 10000005;
const long long UP = 100000000000000LL;

int s = 0, N = 0;
long long result = 0;
int p[MAX], primes[MAX];

int isPrime(long long M) {
    if (M < 2) return 0;
    for (int i = 1; i <= N; i ++) {
        if (1LL * primes[i] * primes[i] > M) {
            break;
        }
        if (M % primes[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void go(long long number, int sum) {
    if (number > UP) return;
    if (sum > 0 && isPrime(number / sum)) {
        for (int i = 1; i < 10; i += 2) {
            if (number * 10 + i < UP && isPrime(number * 10 + i)) {
                result += number * 10 + i;
                if (number * 10 + i < 10000)
                    cerr << "good: " << number * 10 + i << endl;
            }
        }
    }
    //cout << number << " " << sum << endl;
    s ++;
    for (int i = (int)(number == 0); i < 10; i ++) {
        long long to = (number * 10 + i);
        if (to % (sum + i) == 0) {
            go(to, sum + i);
        }
    }
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
    go(0, 0);
    cout << result << endl;
    cout << s << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

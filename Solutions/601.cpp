//
//  main.cpp
//  practice
//
//  Created by Mahmud on 7/25/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int S = 50;

long long gcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
long long p(int s, long long n) {
    --n;
    long long l1 = 1, l2 = 1;
    for (int i = 1; i <= s; i ++) {
        l1 = lcm(l1, i);
    }
    l2 = lcm(l1, s + 1);
    return n / l1 - n / l2;
}

int main() {
    long long result = 0;
    long long pw = 4;
    for (int i = 1; i <= 31; i ++, pw *= 4LL) {
        result += p(i, pw);
        cout << i << " --> " << p(i, pw) << endl;
    }
    --result;
    // need to subtract 1 (1 does not fit when i = 1)
    
    cout << result << endl;
        
    return 0;
}


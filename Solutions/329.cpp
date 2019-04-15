//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/19/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<long long, long long> fraction;

long long gcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}
long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b));
}
void reduce(fraction &f) {
    long long g = gcd(f.first, f.second);
    f.first /= g;
    f.second /= g;
}
fraction add(fraction a, fraction b) {
    fraction c;
    c.second = lcm(a.second, b.second);
    c.first = a.first * (c.second / a.second) + b.first * (c.second / b.second);
    reduce(c);
    return c;
}
fraction add(fraction a, int b) {
    return add(a, fraction(b, 1));
}
fraction reverse(fraction f) {
    fraction a;
    a.first = f.second;
    a.second = f.first;
    return a;
}
fraction multiply(fraction a, fraction b) {
    fraction c;
    c.first = a.first * b.first;
    c.second = a.second * b.second;
    reduce(c);
    return c;
}
fraction multiply(fraction f, int b) {
    return multiply(f, make_pair(b, 1));
}
fraction divide(fraction f, int b) {
    return multiply(f, make_pair(1, b));
}

const int S = 500;

int prime[S + 1];

int main() {
    for (int i = 2; i <= S; i ++) {
        for (int j = i + i; j <= S; j += i) {
            prime[j] = 1;
        }
    }
    prime[1] = 1;
    for (int i = 1; i <= S; i ++) {
        prime[i] ^= 1;
    }
    
    string s = "PPPPNNPPPNPPNPN";
    int PATH_LENGTH = (int)s.size();
    fraction result = fraction(0, 1);
    
    for (int i = 1; i <= S; i ++) {
        for (int j = 0; j < (1 << PATH_LENGTH); j ++) {
            fraction p = fraction(1, S);
            bool valid = true;
            int currentPosition = i;
            for (int k = 0; k < PATH_LENGTH; k ++) {
                if (s[k] == 'P') {
                    if (prime[currentPosition]) {
                        p = multiply(p, fraction(2, 3));
                    }
                    else {
                        p = multiply(p, fraction(1, 3));
                    }
                }
                else {
                    if (prime[currentPosition]) {
                        p = multiply(p, fraction(1, 3));
                    }
                    else {
                        p = multiply(p, fraction(2, 3));
                    }
                }
                if ((j & (1 << k)) && currentPosition == S) {
                    valid = false;
                    break;
                }
                if (!(j & (1 << k)) && currentPosition == 1) {
                    valid = false;
                    break;
                }
                int togo = (int)(currentPosition != S) + (int)(currentPosition != 1);
                p = multiply(p, fraction(1, togo));
                if (j & (1 << k)) {
                    currentPosition ++;
                }
                else {
                    currentPosition --;
                }
            }
            if (valid) {
                result = add(result, p);
                //cout << p.first << " " << p.second << endl;
            }
        }
    }
    cout << result.first << " " << result.second << endl;
    
    return 0;
}

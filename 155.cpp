//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/03/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <set>
#include <utility>

using namespace std;

const int MAX = 100005;

typedef pair<long long, long long> fraction;

set<fraction> s[20];

long long gcd(long long a, long long b) {
    while (a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }
    return a + b;
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
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
fraction multiply(fraction f, int k) {
    return multiply(f, make_pair(k, 1));
}
fraction divide(fraction f, int k) {
    return multiply(f, make_pair(1, k));
}

int main() {
    set<fraction> all;
    for (int i = 1; i <= 18; i ++) {
        s[i].insert(multiply(make_pair(1, 1), i));
        s[i].insert(divide(make_pair(1, 1), i));
        for (int j = 1; j < i; j ++) {
            for (auto f1 : s[j]) {
                for (auto f2: s[i - j]) {
                    s[i].insert(add(f1, f2));
                    s[i].insert(reverse(add(reverse(f1), reverse(f2))));
                }
            }
        }
        cerr << i << " --> " << (int)s[i].size() << endl;
        for (auto j : s[i]) {
            all.insert(j);
        }
    }
    cout << (int)all.size() << endl;
    
    return 0;
}


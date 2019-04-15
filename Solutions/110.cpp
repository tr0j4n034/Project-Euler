//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/10/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 4000000;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int ways = 0;

string best;
vector<int> soFarBest;

int compare(string a, string b) {
    int l1 = (int)a.length();
    int l2 = (int)b.length();
    if (l1 < l2) return -1;
    if (l1 > l2) return 1;
    for (int i = 0; i < l1; i ++) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0;
}
string add(string a, string b) {
    string c = "";
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int q = 0;
    while (i >= 0 || j >= 0) {
        int sum = q;
        if (i >= 0) sum += a[i] - '0';
        if (j >= 0) sum += b[j] - '0';
        if (sum > 9) {
            sum -= 10;
            q = 1;
        }
        else {
            q = 0;
        }
        i --;
        j --;
        c += (char)(sum + '0');
    }
    if (q > 0) {
        c += (char)('1');
    }
    reverse(c.begin(), c.end());
    return c;
}
string multiply(string a, int b) {
    if (b == 1) return a;
    if (b & 1) return add(multiply(a, b - 1), a);
    return multiply(add(a, a), b >> 1);
}
string get(vector<int> factors) {
    string number = "1";
    for (int i = 0; i < (int)factors.size(); i ++) {
        for (int j = 1; j <= factors[i]; j ++) {
            number = multiply(number, primes[i]);
        }
        //logSum += 1. * (long double)factors[i] * log10l((long double)primes[i]);
    }
    return number;
}
void go(long long divisorCount, int lastPrime, int lastPower, string number, vector<int> factors) {
    if (lastPrime > 14) return;
    if (divisorCount > MAX * 2) {
        ways ++;
        if (compare(number, best) == -1) {
            best = number;
            soFarBest = factors;
        }
        return;
    }
    string product = number;
    for (int i = 0; i <= lastPower; i ++) {
        vector<int> to = factors;
        to.push_back(i);
        go(divisorCount * (2 * i + 1), lastPrime + 1, i, product, to);
        product = multiply(product, primes[lastPrime]);
    }
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    best = "";
    for (int i = 1; i < 50; i ++) best += "1";
    
    go(1, 0, 30, "1", vector<int>());
    cout << "ways = " << ways << endl;
    
    cout.precision(20);
    for (auto i: soFarBest) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << best << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

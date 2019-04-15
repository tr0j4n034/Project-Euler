//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 20000001;

int c[] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};

int get(int N) {
    int s = 0;
    while (N > 0) {
        s += c[N % 10];
        N /= 10;
    }
    return s;
}
int digitSum(int N) {
    int s = 0;
    while (N > 0) {
        s += N % 10;
        N /= 10;
    }
    return s;
}

int p[MAX];
int dp[MAX];
string led[10];

/*
 0
 5     1
 6
 4     2
 3
 
 */

int countMatches(int a, int b) {
    int s = 0;
    while (a > 0 && b > 0) {
        int d1 = a % 10;
        int d2 = b % 10;
        for (int i = 0; i < 7; i ++) {
            if (led[d1][i] == '1' && led[d2][i] == '1') s ++;
        }
        a /= 10;
        b /= 10;
    }
    return s;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    led[0] = "1111110";
    led[1] = "0110000";
    led[2] = "1101101";
    led[3] = "1111001";
    led[4] = "0110011";
    led[5] = "1011011";
    led[6] = "1011111";
    led[7] = "1110010";
    led[8] = "1111111";
    led[9] = "1111011";
    
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i < 200; i ++) {
        dp[i] = get(i) + dp[digitSum(i)];
    }
    long long Sam = 0, Max = 0;
    for (int i = MAX / 2; i < MAX; i ++) {
        if (p[i]) continue;
        Sam += get(i) + dp[digitSum(i)];
    }
    Sam *= 2;
    
    for (int i = MAX / 2; i < MAX; i ++) {
        if (p[i]) continue;
        int j = i, last = 0;
        while (j > 0) {
            int now = get(j);
            Max += now - countMatches(last, j);
            //cout << j << " --> " << Max << endl;
            int to = digitSum(j);
            if (to == j) {
                Max += now;
                break;
            }
            else {
                Max += now - countMatches(j, to);
            }
            last = j;
            j = to;
        }
    }
    cout << Max << endl;
    cout << Sam - Max << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}


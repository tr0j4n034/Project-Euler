//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1000000;

int p[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    p[1] = 1;
    
    int N = 11;
    long long sum = 0;
    for (int i = 10; N > 0; i ++) {
        if (p[i]) continue;
        string s = to_string(i);
        int good = 1;
        for (int j = 1; j < (int)s.size(); j ++) {
            good &= !p[stoi(string(s.begin(), s.begin() + j))];
            good &= !p[stoi(string(s.begin() + j, s.end()))];
        }
        if (good) {
            cout << i << endl;
            N --;
            sum += i;
        }
    }
    cout << sum << endl;
    
    return 0;
}

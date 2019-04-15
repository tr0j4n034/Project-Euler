//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <set>
#include <utility>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    
    int N = 1000;
    set<pair<long double, int>> ss;
    
    for (int i = 1; i <= N; i ++) {
        int a = 0, b = 0;
        string s;
        cin >> s;
        int f = 0;
        for (int j = 0; j < (int)s.size(); j ++) {
            if (s[j] == ',') {
                f = j + 1;
                break;
            }
            a = 10 * a + s[j] - '0';
        }
        for (int j = f; j < (int)s.size(); j ++) {
            b = 10 * b + s[j] - '0';
        }
        ss.insert(make_pair(1. * b * log(1. * a), i));
    }
    cout << (*(--ss.end())).second << endl;

    return 0;
}


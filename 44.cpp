//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/15/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

const int MAX = 10000;

set<int> s;

int main() {
    for (int i = 1; i < MAX; i ++) {
        s.insert(i * (3 * i - 1) / 2);
    }
    int result = INT_MAX;
    for (auto i : s) {
        for (auto j : s) {
            if (i == j) break;
            if (s.count(i - j) && s.count(i + j)) {
                if (result > i - j) result = i - j;
            }
        }
    }
    cout << result << endl;
    
    return 0;
}

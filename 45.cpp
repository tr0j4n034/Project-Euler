//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

const int MAX = 1000000;

map<long long, int> m;

int main() {
    for (int i = 1; i < MAX; i ++) {
        m[1LL * i * (i + 1) / 2] ++;
        m[1LL * i * (3 * i - 1) / 2] ++;
        m[1LL * i * (2 * i - 1)] ++;
    }
    for (auto i : m) {
        if (i.second == 3) {
            cout << i.first << endl;
        }
    }
    
    return 0;
}

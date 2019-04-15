//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/15/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 10000;

int p[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    p[1] = 1;
    
    for (int i = 1; i < MAX; i ++) {
        for (int j = 1; i + j + j < MAX; j ++) {
            if (p[i] || p[i + j] || p[i + j + j]) continue;
            string a = to_string(i); sort(a.begin(), a.end());
            string b = to_string(i + j); sort(b.begin(), b.end());
            string c = to_string(i + j + j); sort(c.begin(), c.end());
            if (a == b && a == c) {
                cout << i << " " << i + j << " " << i + j + j << endl;
            }
        }
    }
    return 0;
}

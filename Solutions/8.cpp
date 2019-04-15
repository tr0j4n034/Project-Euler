//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s = "", line;
    long long result = 0;
    
    while (cin >> line) {
        s += line;
        if (line == "?") break;
    }
    
    for (int i = 0; i + 13 < (int)s.size(); i ++) {
        long long p = 1;
        for (int j = i; j < i + 13; j ++) {
            p *= s[j] - '0';
        }
        if (p > result) result = p;
    }
    cout << endl;
    cout << result << endl;
    
    return 0;
}

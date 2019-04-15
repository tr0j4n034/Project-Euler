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


int main() {
    int result = 0;
    for (int i = 1; i < 10000; i ++) {
        string s = "";
        for (int j = i; (int)s.size() < 9; j += i) {
            s += to_string(j);
        }
        if ((int)s.size() != 9) continue;
        string ss = s;
        sort(s.begin(), s.end());
        int good = 1;
        for (int j = 0; j < (int)s.size(); j ++) good &= (s[j] == (char)(j + '1'));
        if (!good) continue;
        int x = stoi(ss);
        if (x > result) result = x;
    }
    cout << result << endl;
    
    return 0;
}

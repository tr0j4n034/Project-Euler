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

int main() {
    auto pal = [](string s) {
        string r = s;
        reverse(s.begin(), s.end());
        return s == r;
    };
    
    long long sum = 0;
    for (int i = 1; i <= MAX; i ++) {
        string s = to_string(i);
        if (!pal(s)) continue;
        int j = i;
        string ss = "";
        while (j > 0) {
            ss += (char)(j % 2);
            j >>= 1;
        }
        if (pal(ss)) sum += i;
    }
    cout << sum << endl;
    
    return 0;
}

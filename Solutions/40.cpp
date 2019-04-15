//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string s = "";
    for (int i = 1; (int)s.size() <= 1000000; i ++) {
        s += to_string(i);
    }
    int result = 1;
    for (int i = 1; i <= 1000000; i *= 10) result *= s[i - 1] - '0';
    cout << result << endl;
    
    return 0;
}

//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX = 1000000005;

int main() {
    for (unsigned long long i = 1000000000; i < 4500000000; i ++) {
        unsigned long long j = i * i;
        string s = to_string(j);
        int g = 1;
        for (int j = 0; j < 18; j += 2) {
            if (s[j] != '0' + (j / 2 + 1) % 10) {
                g = 0;
                break;
            }
        }
        if (g) {
            cout << i << " " << j << endl;
        }
    }
    
    return 0;
}

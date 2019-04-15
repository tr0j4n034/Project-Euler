//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/18/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 100001;

long long sq[MAX];
map<long long, int> m;

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    /// oeisable: http://oeis.org/search?q=17%2C+305%2C+5473&language=english&go=Search
    
    for (int i = 1; i < MAX; i ++) {
        sq[i] = 1LL * i * i;
        m[sq[i]] = i;
    }
    for (int i = 2; i < MAX - 1; i += 2) {
        int h = i + 1;
        if (m.count(sq[i / 2] + sq[h])) {
            cout << i << " " << h << " --> " << m[sq[i / 2] + sq[h]] << endl;
        }
        h = i - 1;
        if (m.count(sq[i / 2] + sq[h])) {
            cout << i << " " << h << " --> " << m[sq[i / 2] + sq[h]] << endl;
        }
    }
    long long result = 0;
    long long a[] = {17, 305, 5473, 98209, 1762289, 31622993, 567451585,
        10182505537LL, 182717648081LL, 3278735159921LL, 58834515230497LL, 1055742538989025LL};
    for (int i = 0; i < 12; i ++) result += a[i];
    
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

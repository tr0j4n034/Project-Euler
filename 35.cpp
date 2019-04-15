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

const int MAX = 10000000;

int p[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    int cnt = 0;
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        wstring s = to_wstring(i);
        wstring ss = s + s;
        int l = (int)s.size();
        int good = 1;
        for (int j = 0; j + l - 1 < l + l && good; j ++) {
            int x = stoi(wstring(ss.begin() + j, ss.begin() + j + l));
            good &= !p[x];
        }
        if (good) cnt ++;
    }
    cout << cnt << endl;
    
    return 0;
}

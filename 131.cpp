//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/12/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <set>
#include <utility>

using namespace std;

const int MAX = 1000000;

int p[MAX];

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i + i; j < MAX; j += i) {
            p[j] = 1;
        }
    }
    int s = 0;
    for (int i = 2; i < MAX; i ++) {
        long long now = 1LL * i * i * i - 1LL * (i - 1) * (i - 1) * (i - 1);
        if (now < MAX && now > 1 && !p[now]) {
            s ++;
        }
    }
    cout << s << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

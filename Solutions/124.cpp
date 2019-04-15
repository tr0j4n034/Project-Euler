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
#include <ctime>

using namespace std;

const int MAX = 100001;

int p[MAX];
pair<int, int> a[MAX];

int main() {
    for (int i = 1; i < MAX; i ++) {
        a[i].first = 1;
        a[i].second = i;
    }
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        for (int j = i; j < MAX; j += i) {
            a[j].first *= i;
            p[j] = 1;
        }
    }
    sort(a + 1, a + MAX);
    cout << a[10000].second << endl;
    
    return 0;
}

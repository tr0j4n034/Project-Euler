//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

const int MAX = 1001;

int good[2 * MAX * MAX];
int cnt[MAX];

int main() {
    for (int i = 1; i < MAX; i ++) good[i * i] = i;
    for (int i = 1; i < MAX; i ++) {
        for (int j = i + 1; j < MAX; j ++) {
            int c = i * i + j * j;
            if (good[c] && i + j + good[c] < MAX) cnt[i + j + good[c]] ++;
        }
    }
    int s = 1;
    for (int i = 1; i < MAX; i ++) {
        if (cnt[i] > cnt[s]) s = i;
    }
    cout << s << endl;
    
    return 0;
}

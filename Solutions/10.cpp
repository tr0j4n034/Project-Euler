//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAX = 2000001;

long long s = 0;
int p[MAX];

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        s += i;
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    cout << s << endl;
    
    return 0;
}

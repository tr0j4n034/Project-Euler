//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/14/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

const int MAX = 10001;

int main() {
    int d = 0, l = 0;
    for (int i = 1; i < 1000; i ++) {
        int j = 1;
        set<int> s;
        for (int k = 1; ; k ++) {
            j = 10 * j % i;
            if (s.count(j)) {
                if (k - 1 > l) {
                    l = k - 1;
                    d = i;
                }
                break;
            }
            s.insert(j);
        }
    }
    cout << d << endl;
    
    return 0;
}

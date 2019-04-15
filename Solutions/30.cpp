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

const int MAX = 10000001;

int main() {
    auto f = [](int x) {
        return x * x * x * x * x;
    };
    long long sum = 0;
    for (int i = 2; i < MAX; i ++) {
        int j = i, s = 0;
        while (j > 0) {
            s += f(j % 10);
            j /= 10;
        }
        if (s == i) {
            sum += i;
        }
    }
    cout << sum << endl;
    
    return 0;
}

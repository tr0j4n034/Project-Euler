//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

long long modulo = 10000000000LL;

int main() {
    long long result = 0;
    for (int i = 1; i <= 1000; i ++) {
        long long s = 1;
        for (int j = 1; j <= i; j ++) {
            s = s * i % modulo;
        }
        result = (result + s) % modulo;
    }
    cout << result << endl;
    
    return 0;
}

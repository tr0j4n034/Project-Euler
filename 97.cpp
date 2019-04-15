//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/15/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long modulo = 10000000000LL;

int main() {
    long long result = 28433;
    for (int i = 1; i <= 7830457; i ++) {
        result = result * 2 % modulo;
    }
    result = (result + 1) % modulo;
    cout << result << endl;
    
    return 0;
}

//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int fib[100];
    fib[1] = 1;
    fib[2] = 2;
    
    for (int i = 3; i < 50; i ++) fib[i] = fib[i - 2] + fib[i - 1];
    int sum = 0;
    for (int i = 1; i < 50; i ++) {
        if (fib[i] > 4000000) break;
        if (fib[i] % 2 == 0) sum += fib[i];
    }
    cout << sum << endl;
    
    return 0;
}

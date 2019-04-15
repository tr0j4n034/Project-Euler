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
    long long N = 600851475143LL;
    long long result = 0;
    for (long long i = 2; i * i <= N; i ++) {
        if (N % i == 0) {
            result = i;
            while (N % i == 0) N /= i;
        }
    }
    if (N > 1) result = N;
    
    cout << result << endl;
    
    return 0;
}

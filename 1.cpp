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
    int sum = 0;
    for (int i = 1; i < 1000; i ++) {
        if (i % 3 == 0 || i % 5 == 0) sum += i;
    }
    cout << sum << endl;
    
    return 0;
}

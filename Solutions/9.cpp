//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int sq[2000005];

int main() {
    for (int i = 2; i < 1000; i ++) sq[i * i] = i;
    for (int i = 1; i < 1000; i ++) {
        for (int j = i + 1; j < 1000; j ++) {
            if (sq[i * i + j * j] && i + j + sq[i * i + j * j] == 1000) {
                cout << i * j * sq[i * i + j * j] << endl;
            }
        }
    }
    
    return 0;
}

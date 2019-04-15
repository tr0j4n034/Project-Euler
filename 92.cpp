//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 100005;

int get(int N) {
    int s = 0;
    while (N > 0) {
        s += (N % 10) * (N % 10);
        N /= 10;
    }
    return s;
}
int f(int N) {
    while (N != 1 && N != 89) {
        N = get(N);
    }
    if (N == 89) return 1;
    else return 0;
}

int main() {
    int s = 0;
    for (int i = 1; i < 10000000; i ++) s += f(i);
    cout << s << endl;
    
    return 0;
}

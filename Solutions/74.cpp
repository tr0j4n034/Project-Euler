//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int f[10];

int get(int N) {
    int sum = 0;
    while (N > 0) {
        sum += f[N % 10];
        N /= 10;
    }
    return sum;
}

int main()
{
    f[0] = 1;
    for (int i = 1; i < 10; i ++) f[i] = f[i - 1] * i;
    
    int result = 0;
    for (int i = 1; i <= 1000000; i ++) {
        int j = i;
        set<int> s;
        while (1) {
            if (s.count(j) || (int)s.size() > 60) break;
            s.insert(j);
            j = get(j);
        }
        if((int)s.size() == 60) result ++;
    }
    cout << result << endl;
    
    return 0;
}
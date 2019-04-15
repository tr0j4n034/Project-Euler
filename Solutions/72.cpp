//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 1000005;

int N;
long long result;
int phi[MAX], lp[MAX];

int main()
{
    cin >> N;
    for (int i = 2; i <= N; i ++) {
        if (lp[i]) continue;
        for (int j = i; j <= N; j += i) {
            lp[j] = i;
        }
    }
    for (int i = 1; i <= N; i ++) phi[i] = i;
    for (int i = 2; i <= N; i ++) {
        int j = i;
        while (j % lp[i] == 0) j /= lp[i];
        phi[i] = phi[j] * (i / j) / lp[i] * (lp[i] - 1);
    }
    for (int i = 2; i <= N; i ++) result += phi[i];
    cout << result << endl;
    
    return 0;
}

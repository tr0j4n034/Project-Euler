//
//  main.cpp
//  practice
//
//  Created by Mahmud on 02/13/18.
//  Copyright © 2017 Mahmud. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int best, l;
int p[MAX];
vector<int> primes;

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (p[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < MAX; j += i) p[j] = 1;
    }
    tie(best, l) = make_tuple(0, 0);
    
    for (int i = 0; i < (int)primes.size(); i ++) {
        int sum = 0, cnt = 0;
        for (int j = i; j < (int)primes.size(); j ++) {
            sum += primes[j];
            cnt ++;
            if (sum > MAX) break;
            if (!p[sum] && cnt > l) {
                l = cnt;
                best = sum;
            }
        }
    }
    cout << best << endl;
    cout << "l = " << l << endl;
    
    return 0;
}

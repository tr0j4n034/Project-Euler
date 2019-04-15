//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/03/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <deque>
#include <utility>

using namespace std;

const int MAX = 20000005;

int dp[MAX], cnt[MAX];
int prime[MAX], active[MAX];

void print(int N) {
    for (int i = 2; i <= N; i ++) {
        if (N % i == 0) {
            int cnt = 0;
            while (N % i == 0) {
                N /= i;
                cnt ++;
            }
            cout << i << " " << cnt << endl;
        }
    }
    cout << endl;
}

int main() {
    for (int i = 2; i < MAX; i ++) {
        if (prime[i]) continue;
        for (int now = i; now < MAX; ) {
            active[now] = 1;
            if (1LL * now * now >= MAX) break;
            now *= now;
        }
        for (int j = i + i; j < MAX; j += i) {
            prime[j] = 1;
        }
    }
    int s = 0, p = 1;
    int need = 500500;
    int modulo = 500500507;
    for (int i = 2; i < MAX && s < need; i ++) {
        if (!active[i]) continue;
        s ++;
        p = 1LL * p * i % modulo;
    }
    if (s < need) cout << "not found" << endl;
    else cout << p << endl;
    
    //    for (int i = 1; i < 20; i ++) {
    //        dp[1 << i] = MAX + 1;
    //    }
    //    for (int i = 1; i < MAX; i ++) {
    //        for (int j = i; j < MAX; j += i) {
    //            cnt[j] ++;
    //        }
    //    }
    //    for (int i = 1; i < MAX; i ++) {
    //        if (dp[cnt[i]] > i) {
    //            dp[cnt[i]] = i;
    //        }
    //    }
    //    for (int i = 0; i < 10; i ++) {
    //        cout << i << " --> " << dp[1 << i] << endl;
    //        print(dp[1 << i]);
    //    }
    
    
    return 0;
}

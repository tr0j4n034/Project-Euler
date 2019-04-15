was = dict()

def solve(N):
    if was.has_key(N):
        return was[N]
    result = 0
    if N <= 1:
        return 1
    elif N % 2 == 0:
        result = solve(N >> 1) + solve((N >> 1) - 1)
    else:
        result = solve(N >> 1)
    was[N] = result
    return result

print(solve(10**25))




'''
    ORIGINAL CPP CODE
    oeis as always...
    link: http://oeis.org/A002487
    
    //
    //  main.cpp
    //  practice
    //
    //  Created by Mahmud on 7/12/18.
    //  Copyright © 2018 Mahmud. All rights reserved.
    //
    
    #include <iostream>
    #include <map>
    
    using namespace std;
    
    const int S = 1005;
    
    const int M = 10;
    
    int get(int n, int k) {
    if (n == 0) return 1;
    if (n < 0 || k < 0) return 0;
    int ans = get(n, k - 1) + get(n - (1 << k), k - 1) + get(n - (1 << (k + 1)), k - 1);
    return ans;
    }
    void printBits(int n) {
    for (int i = M - 1; i >= 0; i --) {
    if (n & (1 << i)) cout << 1;
    else cout << 0;
    }
    cout << endl;
    }
    
    map<long long, long long> was;
    
    long long solve(long long N) {
    if (was.count(N)) return was[N];
    if (N <= 1) return 1;
    if (N & 1) return was[N] = solve(N >> 1);
    else return was[N] = solve(N >> 1) + solve((N >> 1) - 1);
    }
    
    int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    //    for (int i = 1; i < 50; i ++) {
    //        cout << i << " --> " << get(i, M - 1) << " ";
    //        printBits(i);
    //    }
    //    cout << endl;
    //    cout << endl;
    //    for (int i = 1; i < 6; i ++) {
    //        for (int j = (1 << i) - 1; j < (1 << (i + 1)); j ++) {
    //            cout << get(j, M - 1) << " ";
    //        }
    //        cout << endl;
    //    }
    //    for (int i = 1; i < 50; i ++) {
    //        cout << i << " --> " << solve(i) << " " << get(i, M - 1) << endl;
    //    }
    
    long long N = 7482884773727LL;
    cout << solve(N) << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
    }
    
    
    '''

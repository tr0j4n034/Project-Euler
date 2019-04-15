// Author: Sabina A.
// Date: 20.08.16
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>

using namespace std;

const int me = 8000025;

int s[me];

int f(int i, int j, int n){
    if(abs(i - j) % 4)
        return 0;
    int d = (i - j) / 4;
    int x = i - d;
    if(x < 1 || x + d + d < 1)
        return 0;
    return 1;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i < me; i ++)
        for(int j = i; j < me; j += i){
            s[j] += f(i, -j / i, j);
            s[j] += f(-j / i, i, j);
        }
//    int t, n;
//    cin >> t;
//    while(t --){
//        cin >> n;
//        cout << s[n] << endl;
//    }
    
    int result = 0;
    for (int i = 1; i < 1000000; i ++) {
        if (s[i] == 10) result ++;
    }
    cout << result << endl;
    
    return 0;
}

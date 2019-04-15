//
//  main.cpp
//  practice
//
//  Created by Mahmud on 03/20/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>

using namespace std;

struct fraction{
    long long x;
    long long y;
    fraction() {
        
    }
    fraction(long long x, long long y):
    x(x), y(y) {
        
    }
    fraction operator - (const fraction other) const{
        fraction result;
        result.x = x * other.y - y * other.x;
        result.y = y * other.y;
        return result;
    }
    bool operator < (const fraction other) const{
        return x * other.y < y * other.x;
    }
};

int N;
fraction best = fraction(0, 1);
fraction x = fraction(3, 7);

void f(long long lx, long long ly, long long rx, long long ry) {
    if (ly > N || ry > N) return;
    if (fraction(rx, ry) < x) return;
    if (x < fraction(lx, ly)) return;
    //cout << lx << " / " << ly << " to " << rx << " / " << ry << endl;
    if (fraction(lx, ly) < x && best < fraction(lx, ly)) {
        best = fraction(lx, ly);
    }
    if (fraction(rx, ry) < x && best < fraction(rx, ry)) {
        best = fraction(rx, ry);
    }
    f(lx, ly, lx + rx, ly + ry);
    f(lx + rx, ly + ry, rx, ry);
}

int main()
{
    cin >> N;
    
    //f(0, 1, 1, 1);
    
    int ptr = 0;
    for (int i = 1; i <= N; i ++) {
        while (fraction(ptr + 1, i) < x) ptr ++;
        if (best < fraction(ptr, i)) best = fraction(ptr, i);
    }
    cout << best.x << " " << best.y << endl;
    
    return 0;
}

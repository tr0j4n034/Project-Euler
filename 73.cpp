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
    bool operator > (const fraction other) const{
        return x * other.y > y * other.x;
    }
    bool operator == (const fraction other) const{
        return x * other.y == y * other.x;
    }
};

int N;
fraction l = fraction(1, 3);
fraction r = fraction(1, 2);
set<fraction> s;

void f(long long lx, long long ly, long long rx, long long ry) {
    if (ly > N || ry > N) return;
    if (fraction(rx, ry) < l) return;
    if (fraction(lx, ly) > r) return;
    if (fraction(lx, ly) > l && fraction(lx, ly) < r) s.insert(fraction(lx, ly));
    if (fraction(rx, ry) > l && fraction(rx, ry) < r) s.insert(fraction(rx, ry));
    //cout << lx << " / " << ly << " to " << rx << " / " << ry << endl;
    
    f(lx, ly, lx + rx, ly + ry);
    f(lx + rx, ly + ry, rx, ry);
}

int main()
{
    cin >> N;
    
    f(0, 1, 1, 1);
    cout << (int)s.size() << endl;
    
    return 0;
}


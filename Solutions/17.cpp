//
//  main.cpp
//  practice
//
//  Created by Mahmud on 5/17/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cassert>

using namespace std;

const int MAX = 400005;

string a[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string b[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string c[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s = 0;
    for (int i = 1; i <= 100; i ++) {
        string now = "";
        if (i >= 10 && i < 20) now = b[i % 10];
        else if (i < 10) now = a[i];
        else now = c[i / 10] + "" + a[i % 10];
        s += (int)now.size();
        if (i < 10) cout << i << " " << s << endl;
    }
    s *= 10;
    for (int i = 100; i < 1000; i ++) {
        s += (int)a[i / 100].size() + (int)(((string)"hundred").size());
        if (i % 100 != 0) s += 3; // "and"
    }
    s += (int)((string)"one thousand").size() - 1;
    
    cout << s << endl;
    
    return 0;
}

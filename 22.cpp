//
//  main.cpp
//  practice
//
//  Created by Mahmud on 04/30/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100005;

int N;
vector<string> v;

int main() {
    freopen("names.txt", "r", stdin);
    
    string s;
    getline(cin, s);
    string current = "";
    for (int i = 0; i < (int)s.size(); i ++) {
        if (s[i] == '"') {
            if (current != "") v.push_back(current);
            current = "";
        }
        else if(s[i] != ',') current += s[i];
    }
    sort(v.begin(), v.end());
    
    int result = 0;
    for (int i = 0; i < (int)v.size(); i ++) {
        int sum = 0;
        for (int j : v[i]) sum += j - 'A' + 1;
        result += (i + 1) * sum;
    }
    cout << result << endl;
    
    return 0;
}

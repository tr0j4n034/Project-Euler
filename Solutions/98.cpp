//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/08/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAX = 100005;
const int SIZE = 14;

vector<string> words;
vector<string> blocks[SIZE + 1];
vector<long long> squares[SIZE + 1];
map<long long, vector<string>> candidates;
map<string, vector<long long>> ways;

bool match(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
bool isMapped(string a, long long b) {
    string to = to_string(b);
    for (int i = 0; i < (int)a.size(); i ++) {
        for (int j = i + 1; j < (int)a.size(); j ++) {
            if (a[i] != a[j] && to[i] == to[j]) return false;
            if (a[i] == a[j] && to[i] != to[j]) return false;
        }
    }
    return true;
}
bool goodPairs(string a, long long numberA, string b, long long numberB) {
    string A = to_string(numberA);
    string B = to_string(numberB);
    for (int i = 0; i < (int)a.size(); i ++) {
        for (int j = 0; j < (int)a.size(); j ++) {
            if (a[i] == b[j] && A[i] != B[j]) {
                return false;
            }
            if (a[i] != b[j] && A[i] == B[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    freopen("words.txt", "r", stdin);
    
    char ch;
    string text;
    string word = "";
    getline(cin, text);
    for (char ch: text) {
        if (ch == '\"') {
            if ((int)word.size() > 0) {
                words.push_back(word);
            }
            word = "";
        }
        else if (ch != ','){
            word += ch;
        }
    }
    for (auto i: words) {
        blocks[(int)i.size()].push_back(i);
    }
    for (int i = 1; ; i ++) {
        long long to = 1LL * i * i;
        string s = to_string(to);
        if ((int)s.size() > SIZE) break;
        squares[(int)s.size()].push_back(to);
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 1; i <= SIZE; i ++) {
        for (auto number: squares[i]) {
            for (auto word: blocks[i]) {
                if (isMapped(word, number)) {
                    candidates[number].push_back(word);
                    ways[word].push_back(number);
                }
            }
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long result = 0;
    for (int i = 1; i <= SIZE; i ++) {
        for (int j = 0; j < (int)blocks[i].size(); j ++) {
            for (int k = j + 1; k < (int)blocks[i].size(); k ++) {
                if (match(blocks[i][j], blocks[i][k])) {
                    for (auto q: ways[blocks[i][j]]) {
                        for (auto l: ways[blocks[i][k]]) {
                            if (goodPairs(blocks[i][j], q, blocks[i][k], l)) {
                                cout << blocks[i][j] << " vs " << blocks[i][k] << " --> nums: " << q << " " << l << endl;
                                result = max(result, max(q, l));
                            }
                        }
                    }
                }
            }
        }
    }
    cout << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 30005;

int d[MAX], can[MAX];
vector<int> v;

int main() {
    for (int i = 1; i < MAX; i ++) {
        for (int j = i + i; j < MAX; j += i) d[j] += i;
    }
    for (int i = 1; i < MAX; i ++) {
        if (d[i] > i) {
            v.push_back(i);
        }
    }
    for (auto i : v) {
        for (auto j : v) {
            if (i + j >= MAX) break;
            can[i + j] = 1;
        }
    }
    int sum = 0;
    for (int i = 1; i < MAX; i ++) {
        if (can[i] == 0) sum += i;
    }
    cout << sum << endl;
    
    return 0;
}

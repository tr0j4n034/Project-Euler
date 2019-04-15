#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 3005;

int g[MAX];

int main() {
    freopen("input.txt", "r", stdin);
    
    for (int i = 1; i * (i + 1) / 2 < MAX; i ++) {
        g[i * (i + 1) / 2] = 1;
    }
    string s, text = "";
    int count = 0;
    while (getline(cin, s)) {
        text += s;
    }
    s = "";
    int open = 0;
    for (auto i : text) {
        if (i == '"') {
            if (open) {
                if (s.empty() || !isalpha(s[0])) continue;
                int sum = 0;
                for (auto i : s) sum += i - 'A' + 1;
                if (g[sum]) count ++;
                open = 0;
                s = "";
            }
            else {
                open = 1;
            }
        }
        else if (isalpha(i)) s += i;
    }
    cout << count << endl;
    
    return 0;
}

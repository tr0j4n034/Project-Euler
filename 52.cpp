#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 3005;


int main() {
    for (int i = 1; ; i ++) {
        string now = to_string(i);
        sort(now.begin(), now.end());
        int good = 1;
        for (int j = 2; j <= 6; j ++) {
            string to = to_string(i * j);
            sort(to.begin(), to.end());
            if (now != to) {
                good = 0;
                break;
            }
        }
        if (good) {
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}

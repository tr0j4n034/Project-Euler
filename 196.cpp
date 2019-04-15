//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/14/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

const int SIEVE_SIZE = 40000000;
long long OFFSET;

class element {
    long long value;
    int row;
    int column;
    
public:
    element() {
        value = 0;
        row = 0;
        column = 0;
    }
    element(long long v) {
        value = v;
        row = 0;
        for (int i = 25; i >= 0; i --) {
            int to = row + (1 << i);
            if (1LL * to * (to + 1) / 2 <= v) {
                row = to;
            }
        }
        if (1LL * row * (row + 1) / 2 < v) {
            row += 1;
        }
        column = (int)(v - 1LL * row * (row - 1) / 2);
    }
    element(int r, int c) {
        if (r < 1 || c > r) {
            row = -1;
            column = -1;
            value = -1;
        }
        else {
            row = r;
            column = c;
            value = 1LL * r * (r - 1) / 2 + c;
        }
    }
    bool operator == (const element e) {
        return value == e.value;
    }
    long long getValue() {
        return value;
    }
    int getRow() {
        return row;
    }
    int getColumn() {
        return column;
    }
    bool isNeighbor(element e) {
        if (abs(row - e.row) == 1 || abs(column - e.column) == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};

void sieve(long long l, long long r, int *p, int *composites) {
    OFFSET = l;
    int size = (int)(r - l);
    for (int i = 0; i <= size; i ++) {
        p[i] = 0;
    }
    for (int i = 2; 1LL * i * i <= r; i ++) {
        if (composites[i]) continue;
        for (long long j = (l % i == 0 ? l : l - l % i + i); j <= r; j += i) {
            p[j - OFFSET] = 1;
        }
    }
}

int composites[SIEVE_SIZE];
int p[SIEVE_SIZE];
int rows[] = {10000, 5678027, 7208785};

int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    for (int i = 2; i * i < SIEVE_SIZE; i ++) {
        if (composites[i]) continue;
        for (int j = i * i; j < SIEVE_SIZE; j += i) {
            composites[j] = 1;
        }
    }
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    long long result = 0;
    for (int i = 1; i < 3; i ++) {
        long long low = 1LL * (rows[i] - 2) * (rows[i] - 3) / 2 + 1;
        long long high = 1LL * (rows[i] + 2) * (rows[i] + 3) / 2;
        sieve(low, high, p, composites);
        long long currentRowStart = 1LL * rows[i] * (rows[i] - 1) / 2 + 1;
        long long currentRowEnd = currentRowStart + rows[i] - 1;
        long long sum = 0;
        for (long long j = currentRowStart; j <= currentRowEnd; j ++) {
            if (p[j - low]) {
                continue;
            }
            element at = element(j);
            bool found = false;
            for (int dx1 = -1; dx1 <= +1; dx1 ++) {
                for (int dy1 = -1; dy1 <= +1; dy1 ++) {
                    if (found) {
                        break;
                    }
                    if (dx1 * dx1 + dy1 * dy1 == 0) {
                        continue;
                    }
                    element second = element(at.getRow() + dx1, at.getColumn() + dy1);
                    if (second.getValue() == -1 || p[second.getValue() - low]) {
                        continue;
                    }
                    for (int dx2 = -1; dx2 <= +1; dx2 ++) {
                        for (int dy2 = -1; dy2 <= +1; dy2 ++) {
                            if (found) {
                                break;
                            }
                            if (dx2 * dx2 + dy2 * dy2 == 0) {
                                continue;
                            }
                            element third = element(second.getRow() + dx2, second.getColumn() + dy2);
                            if (third.getValue() == -1 || p[third.getValue() - low]) {
                                //continue;
                            }
                            else if (third == at) {
                                //continue;
                            }
                            else {
                                found = true;
                            }
                            third = element(at.getRow() + dx2, at.getColumn() + dy2);
                            if (third.getValue() == -1 || p[third.getValue() - low]) {
                                continue;
                            }
                            if (third == second) {
                                continue;
                            }
                            else {
                                found = true;
                            }
                        }
                    }
                }
            }
            if (found) {
                sum += j;
            }
        }
        cout << sum << endl;
        result += sum;
    }
    cout << "result = " << result << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}


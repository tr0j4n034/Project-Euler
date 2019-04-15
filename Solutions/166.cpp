//
//  main.cpp
//  practice
//
//  Created by Mahmud on 6/13/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

#define for(a, l, r) for (int a = l; a <= r; a ++)

const int MAX = 1000000;


int main() {
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    auto valid = [](int n) {
        if (n < 0 || n > 9) return 0;
        else return 1;
    };
    
    int ways = 0;
    for (a, 0, 9) { // one
        for (b, 0, 9) { // six
            for (c, 0, 9) { // eleven
                for (d, 0, 9) { // sixteen
                    for (e, 0, 9) { // four
                        for (f, 0, 9) { // seven
                            for (g, 0, 9) { // ten
                                for (h, 0, 9) { // two
                                    int sum = a + b + c + d;
                                    int thirteen = sum - e - f - g;
                                    if (!valid(thirteen)) continue;
                                    for (i, 0, 9) { // eight
                                        int twelve = sum - e - i - d;
                                        if (!valid(twelve)) continue;
                                        int nine = sum - g - c - twelve;
                                        if (!valid(nine)) continue;
                                        int five = sum - a - nine - thirteen;
                                        if (!valid(five)) continue;
                                        int three = sum - a - h - e;
                                        if (!valid(three)) continue;
                                        int fifteen = sum - three - f - c;
                                        if (!valid(fifteen)) continue;
                                        int fourteen = sum - thirteen - fifteen - d;
                                        if (!valid(fourteen)) continue;
                                        if (a + five + nine + thirteen != sum) continue;
                                        if (h + b + g + fourteen != sum) continue;
                                        if (three + f + c + fifteen != sum) continue;
                                        if (e + i + twelve + d != sum) continue;
                                        if (a + h + three + e != sum) continue;
                                        if (five + b + f + i != sum) continue;
                                        if (nine + g + c + twelve != sum) continue;
                                        if (thirteen + fourteen + fifteen + d != sum) continue;
                                        ways ++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ways << endl;
    
    cerr << "done in: " << 1. * clock() / CLOCKS_PER_SEC << endl;
    
    return 0;
}


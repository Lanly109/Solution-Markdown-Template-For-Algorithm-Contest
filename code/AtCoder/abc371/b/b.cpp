/*
 * Author: Lanly
 * Time: 2024-09-14 20:05:18
 */

#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y)                                                           \
    for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y)                                                          \
    for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> tora(n, 0);
    while (m--) {
        int f;
        string s;
        cin >> f >> s;
        --f;
        if (s[0] == 'F' || tora[f]) {
            cout << "No" << '\n';
        } else {
            tora[f] = 1;
            cout << "Yes" << '\n';
        }
    }

    return 0;
}

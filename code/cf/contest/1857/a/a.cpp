/*
 * Author: Lanly
 * Time: 2023-08-08 15:27:02
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int odd = 0;
        while (n--) {
            int a;
            cin >> a;
            odd += (a & 1);
        }
        if (odd & 1)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }

    return 0;
}

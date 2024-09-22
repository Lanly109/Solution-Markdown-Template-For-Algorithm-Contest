/*
 * Author: Lanly
 * Time: 2022-12-17 13:05:54
*/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int s, t;
    cin >> s >> t;
    int ans = 0;
    FOR(i, 0, s + 1)
        FOR(j, i, s + 1)
            FOR(k, j, s + 1)
                ans += (i + j + k <= s && 1ll * i * j * k <= t);
    cout << ans << '\n';
        

    return 0;
}

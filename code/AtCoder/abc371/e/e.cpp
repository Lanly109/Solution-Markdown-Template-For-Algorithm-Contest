/*
 * Author: Lanly
 * Time: 2024-09-14 20:29:08
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
        --i;
    }
    vector<int> r(n);
    vector<int> pos(n, n);
    for (int i = n - 1; i >= 0; --i) {
        r[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    fill(pos.begin(), pos.end(), 0);
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        int lcnt = i + 1;
        int rcnt = r[i] - i;
        ans += 1ll * lcnt * rcnt;
    }
    cout << ans << '\n';

    return 0;
}

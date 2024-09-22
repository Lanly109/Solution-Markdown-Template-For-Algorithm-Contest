/*
 * Author: Lanly
 * Time: 2023-08-08 16:02:15
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
        vector<LL> a(n), id(n), ans(n);
        for (auto& i : a)
            cin >> i;
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y) { return a[x] < a[y]; });
        LL val = 0;
        int l = 0;
        int pos = a[id[0]];
        for (int i = 0; i < n; ++i) {
            val += abs(a[i] - a[id[0]] + 1);
        }
        ans[id[0]] = val;

        for (auto& i : id) {
            val += 1ll * (a[i] - pos) * (l - n + l);
            ans[i] = val;
            l++;
            pos = a[i];
        }
        for (auto& i : ans)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}

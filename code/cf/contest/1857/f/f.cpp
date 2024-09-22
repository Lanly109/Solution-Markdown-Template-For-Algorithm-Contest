/*
 * Author: Lanly
 * Time: 2023-08-08 16:20:31
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
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int q;
        cin >> q;
        while (q--) {
            LL x, y;
            cin >> x >> y;
            LL delta = x * x - 4 * y;
            if (delta < 0) {
                cout << 0 << ' ';
                continue;
            }
            LL h = sqrt(delta);
            if (h * h != delta) {
                cout << 0 << ' ';
                continue;
            }
            if ((x & 1) ^ (h & 1)) {
                cout << 0 << ' ';
                continue;
            }
            if (h == 0) {
                LL ans = x / 2;
                cout << 1ll * cnt[ans] * (cnt[ans] - 1) / 2 << ' ';
            } else {
                LL ans1 = (x + h) / 2, ans2 = (x - h) / 2;
                cout << 1ll * cnt[ans1] * cnt[ans2] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

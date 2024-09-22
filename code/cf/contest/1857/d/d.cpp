/*
 * Author: Lanly
 * Time: 2023-08-08 15:54:41
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
        vector<int> a(n), b(n), d(n), id(n);
        for (auto& i : a)
            cin >> i;
        for (auto& i : b)
            cin >> i;
        for (int i = 0; i < n; ++i)
            d[i] = a[i] - b[i];
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int a, int b) { return d[a] > d[b]; });
        vector<int> ans;
        for (int i = 1; i < n; ++i) {
            int cur = id[i], la = id[i - 1];
            ans.push_back(la);
            if (d[cur] != d[la])
                break;
            if (i == n - 1)
                ans.push_back(cur);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (auto& i : ans)
            cout << i + 1 << ' ';
        cout << '\n';
    }

    return 0;
}

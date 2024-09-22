/*
 * Author: Lanly
 * Time: 2023-08-08 15:44:26
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
        vector<int> a(n * (n - 1) / 2);
        for (auto& i : a)
            cin >> i;
        sort(a.begin(), a.end());
        vector<int> ans;
        for (int i = 0, len = n - 1; i < a.size(); i += len, --len) {
            ans.push_back(a[i]);
        }
        ans.push_back(a.back());
        for (auto& i : ans)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}

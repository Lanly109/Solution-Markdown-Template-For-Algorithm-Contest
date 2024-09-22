/*
 * Author: Lanly
 * Time: 2024-09-14 20:17:37
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
    vector<int> x(n);
    for (auto& i : x)
        cin >> i;
    vector<LL> p(n);
    for (auto& i : p)
        cin >> i;
    vector<LL> presum(n);
    partial_sum(p.begin(), p.end(), presum.begin());
    auto get_sum = [&](int l, int r) {
        if (l > r)
            return 0ll;
        return presum[r] - (l ? presum[l - 1] : 0);
    };
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto L = lower_bound(x.begin(), x.end(), l) - x.begin();
        auto R = upper_bound(x.begin(), x.end(), r) - x.begin();
        cout << get_sum(L, R - 1) << '\n';
    }

    return 0;
}

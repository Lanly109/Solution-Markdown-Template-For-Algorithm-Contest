/*
 * Author: Lanly
 * Time: 2024-09-14 20:01:20
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
    string a, b, c;
    cin >> a >> b >> c;
    array<int, 3> id{};
    iota(id.begin(), id.end(), 0);
    map<pair<int, int>, int> mp;
    mp[{0, 1}] = a[0] == '>';
    mp[{1, 0}] = a[0] == '<';
    mp[{0, 2}] = b[0] == '>';
    mp[{2, 0}] = b[0] == '<';
    mp[{1, 2}] = c[0] == '>';
    mp[{2, 1}] = c[0] == '<';
    sort(id.begin(), id.end(), [&](int x, int y) { return mp[{x, y}]; });
    string ans = "ABC";
    cout << ans[id[1]] << '\n';

    return 0;
}

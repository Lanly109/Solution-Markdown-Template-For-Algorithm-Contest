/*
 * Author: Lanly
 * Time: 2024-09-14 20:09:48
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
    array<int, 2> m{};
    array<vector<vector<int>>, 2> edge{vector<vector<int>>(n, vector<int>(n)),
                                       vector<vector<int>>(n, vector<int>(n))};
    for (int k = 0; k < 2; ++k) {
        cin >> m[k];
        for (int i = 0; i < m[k]; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            edge[k][u][v] = edge[k][v][u] = 1;
        }
    }
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    int ans = 1e9 + 7;
    auto solve = [&](vector<int> id) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (edge[0][id[i]][id[j]] != edge[1][i][j]) {
                    res += a[i][j];
                }
            }
        }
        return res;
    };
    do {
        ans = min(ans, solve(id));
    } while (next_permutation(id.begin(), id.end()));

    cout << ans << '\n';

    return 0;
}

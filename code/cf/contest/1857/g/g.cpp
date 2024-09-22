/*
 * Author: Lanly
 * Time: 2023-08-08 16:43:52
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

class dsu {
  public:
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        sz.resize(n);
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            sz[y] += sz[x];
            return true;
        }
        return false;
    }
};

const LL mo = 998244353;

long long qpower(long long a, long long b) {
    long long qwq = 1;
    while (b) {
        if (b & 1)
            qwq = qwq * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return qwq;
}

long long inv(long long x) { return qpower(x, mo - 2); }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<array<int, 3>> edge(n - 1);
        for (auto& i : edge) {
            cin >> i[0] >> i[1] >> i[2];
            --i[0], --i[1];
        }
        vector<int> id(n - 1);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(),
             [&](int x, int y) { return edge[x][2] < edge[y][2]; });
        dsu d(n);
        LL ans = 1;
        for (auto& i : id) {
            int u = edge[i][0], v = edge[i][1], w = edge[i][2];
            int fu = d.get(u), fv = d.get(v);
            ans = (ans * qpower(s - w + 1, 1ll * d.sz[fu] * d.sz[fv] - 1)) % mo;
            d.unite(u, v);
        }
        cout << ans << '\n';
    }

    return 0;
}

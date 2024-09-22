/*
 * Author: Lanly
 * Time: 2024-09-14 20:40:43
 */

#include <bits/stdc++.h>
using namespace std;
using LL = __int128;
#define FOR(i, x, y)                                                           \
    for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y)                                                          \
    for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif

LL x, y, d;

void exgcd(LL& x, LL& y, LL a, LL b) {
    if (!b)
        d = a, x = 1, y = 0;
    else
        exgcd(y, x, b, a % b), y -= a / b * x;
}

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }

LL a, b, A, B;

void merge() {
    exgcd(x, y, a, A);
    LL c = B - b;
    assert(c % d == 0);
    x = x * c / d % (A / d);
    if (x < 0)
        x += A / d;
    LL mod = lcm(a, A);
    b = (a * x + b) % mod;
    if (b < 0)
        b += mod;
    a = mod;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), v(n);
    for (auto& i : p) {
        cin >> i;
        --i;
    }
    for (auto& i : v)
        cin >> i;
    vector<vector<int>> cir;
    vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i])
            continue;
        vector<int> h{i};
        for (int j = p[i]; j != i; j = p[j]) {
            vis[j] = 1;
            h.push_back(j);
        }
        cir.push_back(h);
    }
    a = 1;
    b = 0;
    for (int i = 0; i < cir.size(); ++i) {
        auto& h = cir[i];
        int id = b % h.size();
        vector<int> used(h.size(), 0);
        for (int i = id;; i = (i + a) % h.size()) {
            if (used[i])
                break;
            used[i] = 1;
            if (v[h[i]] < v[h[id]])
                id = i;
        }
        A = h.size();
        B = id;
        if (i > 0)
            merge();
        else
            a = A, b = B;
    }
    LL step = b % a;
    vector<int> ans(n);
    for (auto& h : cir) {
        for (int i = 0, j = step % h.size(); i < h.size();
             i++, j = (j + 1) % h.size()) {
            ans[h[i]] = v[h[j]];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}

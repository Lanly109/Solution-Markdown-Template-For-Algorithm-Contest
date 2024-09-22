/*
 * Author: Lanly
 * Time: 2024-09-15 10:22:08
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

struct Block {
    int l, r, id;
    bool operator<(const Block& b) const { return id < b.id; }
    inline int cnt() const { return r - l + 1; }
    inline int lid() const { return id; }
    inline int rid() const { return id + cnt() - 1; }
    bool intersect(const Block& b, int is_right) const {
        if (is_right)
            return r >= b.l;
        else
            return l <= b.r;
    }
    pair<Block, Block> cut(int t) const {
        int cnt = t - id;
        return {{l, l + cnt - 1, id}, {l + cnt, r, id + cnt}};
    }
    Block shift(int dis) const {
        auto ret = *this;
        ret.l += dis;
        ret.r += dis;
        return ret;
    }
    Block merge(const Block& b) const {
        assert(r + 1 == b.l || b.r + 1 == l);
        return {min(l, b.l), max(r, b.r), min(id, b.id)};
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<Block> p;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        p.insert({x, x, i});
    }
    auto get_block = [&](int t) {
        auto it = prev(p.upper_bound({0, 0, t}));
        return it;
    };
    auto get_pos = [&](int t) {
        auto it = get_block(t);
        int ret = it->l + t - it->id;
        return ret;
    };
    auto shift_block = [&](int t, int g) {
        auto it = *get_block(t);
        auto dis = g - get_pos(t);
        it.l += dis;
        it.r += dis;
        return it;
    };
    auto solve = [&](int t, int g) {
        LL sum = 0;
        while (true) {
            int pos = get_pos(t);
            if (pos == g)
                break;
            auto it = get_block(t);
            if (pos < g) {
                if (it->lid() != t) {
                    auto [lblock, rblock] = it->cut(t);
                    p.erase(it);
                    p.insert(lblock);
                    p.insert(rblock);
                } else {
                    auto sit = shift_block(t, g);
                    auto nit = next(it);
                    if (nit == p.end() || !sit.intersect(*nit, true)) {
                        sum += 1ll * it->cnt() * (g - pos);
                        p.erase(it);
                        p.insert(sit);
                    } else {
                        auto shift = nit->l - it->r - 1;
                        sum += 1ll * sit.cnt() * shift;
                        sit = it->shift(shift);
                        auto nblock = sit.merge(*nit);
                        auto tmp = *nit;
                        p.erase(it);
                        p.erase(tmp);
                        p.insert(nblock);
                    }
                }
            } else {
                if (it->rid() != t) {
                    auto [lblock, rblock] = it->cut(t + 1);
                    p.erase(it);
                    p.insert(lblock);
                    p.insert(rblock);
                } else {
                    auto sit = shift_block(t, g);
                    if (it == p.begin() || !sit.intersect(*prev(it), false)) {
                        sum += 1ll * sit.cnt() * (pos - g);
                        p.erase(it);
                        p.insert(sit);
                    } else {
                        auto pit = prev(it);
                        auto shift = it->l - pit->r - 1;
                        sum += 1ll * sit.cnt() * shift;
                        sit = it->shift(-shift);
                        auto nblock = sit.merge(*pit);
                        auto tmp = *pit;
                        p.erase(it);
                        p.erase(tmp);
                        p.insert(nblock);
                    }
                }
            }
        }
        return sum;
    };
    int q;
    cin >> q;
    LL ans = 0;
    while (q--) {
        int t, g;
        cin >> t >> g;
        --t;
        LL ret = solve(t, g);
        ans += ret;
    }
    cout << ans << '\n';

    return 0;
}

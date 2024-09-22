/*
 * Author: Lanly
 * Time: 2022-12-17 15:02:23
*/

#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

const LL inf = 1e18;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    LL n, s;
    cin >> n >> s;
    LL ans = inf;
    auto calc = [](LL x, int base){
        LL cnt = 0;
        while(x){
            cnt += x % base;
            x /= base;
        }
        return cnt;
    };
    for(int i = 2; i <= 100000; ++ i){
        if (calc(n, i) == s){
            ans = i;
            break;
        }
    }
    if (ans == inf){
        for(int i = 1; i <= 100000; ++ i){
            LL mod = s - i;
            if (n > mod && (n - mod) % i == 0){
                LL p = (n - mod) / i;
                if (p != 1){
                    ans = min(ans, p);
                    debug(p, i, mod);
                }
            }
        }
    }

    if (ans == inf)
        ans = -1;
    if (n == s && ans == -1)
        ans = n + 1;
    cout << ans << '\n';

    return 0;
}

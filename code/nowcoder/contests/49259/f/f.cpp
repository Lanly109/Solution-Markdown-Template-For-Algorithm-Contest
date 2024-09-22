/*
 * Author: Lanly
 * Time: 2022-12-17 13:45:37
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

const LL inf = 1e18 + 7;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<LL, LL> cnt, ans;
    for(int i = 0; i < n; ++ i){
        LL x;
        cin >> x;
        LL cc = 0;
        while(x >= 3){
            ans[x] += cc;
            cnt[x] ++;
            ++ cc;
            x /= 3;
        }
    }
    LL val = inf;
    for(auto &i : cnt)
        if (i.second == n)
            val = min(val, ans[i.first]);
    if (val == inf)
        cout << "Lose" << '\n';
    else 
        cout << val << '\n';

    return 0;
}

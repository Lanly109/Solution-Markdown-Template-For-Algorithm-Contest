/*
 * Author: Lanly
 * Time: 2022-12-17 14:48:25
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    while(t--){
        int l, r;
        cin >> l >> r;
        -- l;
        -- r;
        int ans = 0;
        for(int i = l; i <= r; ++ i)
            ans += (a[i] >= a[l]);
        cout << ans << '\n';
    }

    return 0;
}

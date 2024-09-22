/*
 * Author: Lanly
 * Time: 2022-12-17 16:39:00
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

const LL inf = 1e18;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<LL> dp(3001, inf);
    dp[0] = 0;
    vector<pair<LL, int>> f(n);
    for(auto &i : f)
        cin >> i.first >> i.second;
    sort(f.begin(), f.end(), [](const pair<LL, int>& a, const pair<LL, int>& b){
            return a.first < b.first;
            });
    for(int i = 0; i < n; ++ i){
        LL a;
        int b;
        a = f[i].first;
        b = f[i].second;
        for(int j = 3000; j >= b; -- j){
            if (a > dp[j - b])
                dp[j] = min(dp[j], dp[j - b] + a);
        }
    }
    int ans = 0;
    for(int i = 3000; i >= 0; -- i)
        if (dp[i] != inf){
            ans = i;
            break;
        }
    cout << ans << '\n';
    return 0;
}

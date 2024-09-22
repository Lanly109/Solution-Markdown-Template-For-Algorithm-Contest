/*
 * Author: Lanly
 * Time: 2022-12-17 13:20:34
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

const int N = 1e5 + 8;
int cnt[N], t, k;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    cin >> t >> k;
    for(int i = 1; i <= t; ++ i){
        int l, r;
        cin >> l >> r;
        cnt[l] ++;
        cnt[r + 1] --;
    }
    vector<pair<int, int>> ans;
    int st = 0;
    bool ok = true;
    int sum = 0;
    for(int i = 0; i <= 120; ++ i){
        sum += cnt[i];
        if (ok && sum >= k){
            ans.push_back({st, i - 1});
            ok = false;
        }else if (sum < k){
            if (!ok)
                st = i;
            ok = true;
        }
    }
    if (ok)
        ans.push_back({st, 120});
    cout << ans.size() << '\n';
    for(auto &i : ans)
        cout << i.first << '-' << i.second << '\n';

    return 0;
}

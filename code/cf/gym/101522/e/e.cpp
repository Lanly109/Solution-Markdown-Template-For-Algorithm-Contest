/*
 * Author: Lanly
 * Time: 2023-01-11 18:55:44
*/

#include <bits/stdc++.h>
#include <iomanip>
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
    int n, r;
    cin >> n >> r;
    vector<set<int>> box(2 * n + 1);
    set<int> pos;
    int cur = 0;
    for(int i = 1; i < r; ++ i){
        int x, y, cx, cy;
        cin >> x >> y >> cx >> cy;
        box[cx].insert(x);
        box[cy].insert(y);
        pos.insert(x);
        pos.insert(y);
        if (cx == cy)
            cur = max(cur, cx);
    }
    double ans1 = 0;
    for(int i = n; i >= 1; -- i){
        if (box[i].size() == 2){
            ans1 = max(ans1, 1.0 * i);
        }
    }
    int lar1 = n;
    for(; lar1 >= 1; -- lar1){
        if (box[lar1].size() == 1){
            break;
        }
    }
    int unknown = 2 * n - pos.size();
    double single = 1.0 / unknown;
    double ans2 = single * lar1 + (1 - single) * cur;

    double two = (2.0 / unknown) * (1.0 / (unknown - 1));
    double ans3 = 0;
    int cnt = 0;
    for(int i = cur + 1; i <= n; ++ i){
        if (box[i].empty()){
            ans3 += two * i;
            ++ cnt;
        }
    }
    ans3 += (1 - cnt * two) * cur;

    double ans = max({ans1, ans2, ans3});
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}

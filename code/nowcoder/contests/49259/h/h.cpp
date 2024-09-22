/*
 * Author: Lanly
 * Time: 2022-12-17 14:15:51
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

const LL mo = 1e9 + 7;

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<LL> a(n);
    for(auto &i : a){
        cin >> i;
    }
    sort(a.begin(), a.end(), [](LL a, LL b){
            return abs(a) > abs(b);
            });
    int kp = -1, kn = -1;
    int cnt = 0;
    for(int i = 0; i < k; ++ i){
        cnt ^= (a[i] < 0);
        if (a[i] > 0)
            kp = i;
        else if (a[i] < 0)
            kn = i;
    }
    // first k
    if (cnt == 0){
        LL ans = 1;
        for(int i = 0; i < k; ++ i)
            ans = ans * abs(a[i]) % mo;
        cout << ans << '\n';
        return 0;
    }
    int kkp = -1, kkn = -1;
    for(int i = k; i < n; ++ i){
        if (kkp == -1 && a[i] > 0)
            kkp = i;
        if (kkn == -1 && a[i] < 0)
            kkn = i;
    }
    // swap biggest last positive with smallest k neg
    if (kkp != -1 && (kkp < kkn || kkn == -1 || kp == -1)){
        LL ans = 1;
        for(int i = 0; i < k; ++ i){
            if (i == kn)
                continue;
            ans = ans * abs(a[i]) % mo;
        }
        ans = ans * a[kkp] % mo;
        cout << ans << '\n';
        return 0;
    }
    // swap biggest last negative with smallest k positive
    if (kkn != -1 && kp != -1){
        LL ans = 1;
        for(int i = 0; i < k; ++ i){
            if (i == kp)
                continue;
            ans = ans * abs(a[i]) % mo;
        }
        ans = ans * abs(a[kkn]) % mo;
        cout << ans << '\n';
        return 0;
    }
    // ans < 0, last k
    LL ans = 1;
    for(int i = n - 1; i > n - 1 - k; -- i){
        ans = ans * abs(a[i]) % mo;
    }
    cout << -ans << '\n';

    return 0;
}

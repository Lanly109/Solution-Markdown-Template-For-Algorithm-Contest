/*
 * Author: Lanly
 * Time: 2022-12-17 13:43:13
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

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string n, k;
        cin >> n >> k;
        cout << n.back() << '\n';
    }

    return 0;
}

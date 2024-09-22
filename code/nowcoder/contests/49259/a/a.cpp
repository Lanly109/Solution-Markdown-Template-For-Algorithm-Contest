/*
 * Author: Lanly
 * Time: 2022-12-17 13:01:52
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
    int n;
    cin >> n;
    bool ok = false, haveC = false, haveV = false;
    while(n--){
        string s;
        cin >> s;
        if (s.size() == 4)
            ok = true;
        else if (s.size() == 6)
            ok = false;
        else if (ok && s[0] == 'C')
            haveC = true;
        else if (ok && s[0] == 'V' && haveC)
            haveV = true;
    }
    if (haveV)
        cout << "Yes" << '\n';
    else 
        cout << "No" << '\n';

    return 0;
}

/*
 * Author: Lanly
 * Time: 2023-08-08 15:32:30
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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.front() >= '5') {
            string ans = "1" + string(s.size(), '0');
            cout << ans << '\n';
        } else {
            int pos = s.size();
            for (int i = s.size() - 1; i >= 1; --i) {
                if (s[i] >= '5') {
                    s[i - 1]++;
                    s[i] = '0';
                    pos = i;
                }
            }
            if (s.front() >= '5') {
                string ans = "1" + string(s.size(), '0');
                cout << ans << '\n';
            } else {
                cout << s.substr(0, pos) + string(s.size() - pos, '0') << '\n';
            }
        }
    }

    return 0;
}

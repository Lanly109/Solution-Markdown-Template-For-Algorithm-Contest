/*
 * Author: Lanly
 * Time: 2022-12-17 13:55:33
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

const int N = 200;
int dp[N][N];

int solve(int x, int y){
    if (dp[x][y] != -1)
        return dp[x][y];
    int v1 = 1, v2 = 1, v3 = 1;
    if (x > 0){
        v1 = solve(x - 1, y);
        v2 = solve(x - 1, y + 1);
    }
    if (y > 0){
        v3 = solve(x, y - 1);
    }
    if (v1 == 0 || v2 == 0 || v3 == 0)
        dp[x][y] = 1;
    else 
        dp[x][y] = 0;
    return dp[x][y];
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    // memset(dp, -1, sizeof(dp));
    // dp[0][0] = 0;
    // for(int i = 0; i < N; ++ i)
    //     for(int j = 0; j < N; ++ j){
    //         solve(i, j);
    //     }
    // for(int i = 0; i < N; ++ i){
    //     debug(i * 2, dp[i][0]);
    //     debug(i * 2 + 1, dp[i][1]);
    // }
    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;
        if ((n & 1) || ((n / 2) & 1)){
            cout << "Mazige" << '\n';
        }else{
            cout << "Not Mazige" << '\n';
        }
    }

    return 0;
}

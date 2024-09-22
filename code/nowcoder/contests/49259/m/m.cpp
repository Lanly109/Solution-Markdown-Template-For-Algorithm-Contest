/*
 * Author: Lanly
 * Time: 2022-12-17 15:22:56
*/

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)

#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

const long double inf = 1e18;
const long double pi = acos(-1);
const long double sin18 = sin(18.0 / 180 * pi);
const long double sin36 = sin(36.0 / 180 * pi);
const long double sin72 = sin(72.0 / 180 * pi);
const long double sin108 = sin(108.0 / 180 * pi);
const long double cos18 = cos(18.0 / 180 * pi);
const long double cos72 = cos(72.0 / 180 * pi);
const long double cos108 = cos(108.0 / 180 * pi);
const long double tan54 = tan(54.0 / 180 * pi);
const long double eps = 1e-10;

long double calcB(long double a){
    return 2.0 * a * sin18;
}

long double hoc(long double a){
    long double b = calcB(a);
    return a + a + b;
}

long double vec(long double a){
    return hoc(a) * cos18;
}

long double star(long double a){
    return 5.0 * 0.5 * a * a * sin36;
}

long double wubian(long double b){
    return 5.0 * 0.5 * b * b / 2 * tan54;
}


long double area(long double a){
    long double b = calcB(a);
    long double s1 = star(a);
    long double s2 = wubian(b);
    return s1 + s2;
}

long double solve(long double (*f)(long double), long double up){
    long double l = 0, r = up;
    while(l + eps < r){
        long double mid = (l + r) / 2;
        if (f(mid) <= up)
            l = mid;
        else 
            r = mid;
    }
    return l;
}

long double cot(long double x){
    return tan(pi/2-x);
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    long double x, y;
    cin >> x >> y;
    cout << 5.0 / 8.0 * (x * x + y * y) * cot(pi / 5) << '\n';
    long double ff = min(x, y);
    long double a = sqrt(ff * ff / ((sin72 * sin72 + (1 + cos72) * (1 + cos72)) * sin108 * sin108 * 2 * (1 - cos108)));
    long double b = min(solve(hoc, x), solve(vec, y));

    cout << fixed << setprecision(10) << area(a) << ' ' << area(b) << '\n';
    // cout << fixed << setprecision(10) << area(a) << '\n';

    return 0;
}

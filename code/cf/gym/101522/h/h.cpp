/*
 * Author: Lanly
 * Time: 2023-01-11 18:25:35
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

typedef double db;
const db EPS = 1e-9;

inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }
  
inline int cmp(db a, db b){ return sign(a-b); }
  
struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return {x + p.x, y + p.y}; }
	P operator-(P p) { return {x - p.x, y - p.y}; }
	P operator*(db d) { return {x * d, y * d}; }
	P operator/(db d) { return {x / d, y / d}; }
 
	bool operator<(P p) const {  // 字典序小于
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}
 
	bool operator==(P o) const{  // 判断点相等
		return cmp(x,o.x) == 0 && cmp(y,o.y) == 0;
	}
 
	db dot(P p) { return x * p.x + y * p.y; }   // 点积
	db det(P p) { return x * p.y - y * p.x; }   // 叉积
	 
	db distTo(P p) { return (*this-p).abs(); }  // 两点距离
	db alpha() { return atan2(y, x); }          // 斜率
	void read() { cin>>x>>y; }                  // 读取
	void write() {cout<<"("<<x<<","<<y<<")"<<endl;} // 输出
	db abs() { return sqrt(abs2());}        // 距离原点的距离，向量长度
	db abs2() { return x * x + y * y; }     // 原点距离平方
	P rot90() { return P(-y,x);}            // 逆时针旋转90度
	P unit() { return *this/abs(); }        // 单位向量
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); } // 是否在0～179度？点在上半边，极角排序用的
	P rot(db an){ return {x*cos(an)-y*sin(an),x*sin(an) + y*cos(an)}; }         // 逆时针旋转an度
};
  
int type(P o1,db r1,P o2,db r2){    // 两个圆的关系，0:内含,1:内切,2:相交,3:外切,4:相离
	db d = o1.distTo(o2);
	if(cmp(d,r1+r2) == 1) return 4;
	if(cmp(d,r1+r2) == 0) return 3;
	if(cmp(d,abs(r1-r2)) == 1) return 2;
	if(cmp(d,abs(r1-r2)) == 0) return 1;
	return 0;
}
  
vector<P> isCC(P o1, db r1, P o2, db r2) { //need to check whether two circles are the same
	db d = o1.distTo(o2); 
	if (cmp(d, r1 + r2) == 1) return {};
	if (cmp(d,abs(r1-r2))==-1) return {};
	d = min(d, r1 + r2);
	db y = (r1 * r1 + d * d - r2 * r2) / (2 * d), x = sqrt(r1 * r1 - y * y);
	P dr = (o2 - o1).unit();
	P q1 = o1 + dr * y, q2 = dr.rot90() * x;
	return {q1-q2,q1+q2};//along circle 1
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    P p1, p2;
    int r1, r2;
    p1.read();
    cin >> r1;
    p2.read();
    cin >> r2;
    int sign = type(p1, r1, p2, r2);
    assert(sign != 4);
    if (sign == 0 || sign == 1){
        if (r1 < r2)
            cout << fixed << setprecision(10) << p1.x << ' ' << p1.y << '\n';
        else 
            cout << fixed << setprecision(10) << p2.x << ' ' << p2.y << '\n';
    }else{
        auto good = isCC(p1, r1, p2, r2);
        cout << fixed << setprecision(10) << good.front().x << ' ' << good.front().y << '\n';
    }

    return 0;
}

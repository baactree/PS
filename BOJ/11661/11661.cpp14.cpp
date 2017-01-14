#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;
typedef long long int ll;
ll s, t;
ll gcd(ll a, ll b){
	ll r, r1, r2;
	ll _s, s1, s2;
	ll _t, t1, t2;
	r1 = a;
	r2 = b;
	s1 = 1;
	s2 = 0;
	t1 = 0;
	t2 = 1;
	ll q;
	while (r2 > 0){
		q = r1 / r2;
		r = r1 - q*r2;
		r1 = r2;
		r2 = r;
		_s = s1 - q*s2;
		s1 = s2;
		s2 = _s;
		_t = t1 - q*t2;
		t1 = t2;
		t2 = _t;
	}
	s = s1;
	t = t1;
	return r1;
	
}
int main(){
	ll a, b, c, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
	if (x1 > x2 || y1 > y2){
		printf("0\n");
		return 0;
	}
	int xsign, ysign;
	xsign = ysign = 1;//양수
	if (a < 0)
		xsign *= -1;
	if (b < 0)
		ysign *= -1;
	if (c > 0){
		xsign *= -1;
		ysign *= -1;
	}
	if (a == 0 && b == 0 && c == 0){
		//무수히 많은 해 존재
		ll temp1, temp2;
		temp1 = x2 - x1 + 1;
		temp2 = y2 - y1 + 1;
		printf("%lld\n", temp1*temp2);
	}
	else if (a == 0 && b == 0){
		//해가 없음
		printf("0\n");
	}
	else if (a == 0){
		//y=-c/b x=무한
		if (c%b==0&&-c / b >= y1&&-c / b <= y2)
			printf("%lld\n", x2 - x1 + 1);
		else
			printf("0\n");
	}
	else if (b == 0){
		//x=-c/a y=무한
		if (c%a==0&&-c / a >= x1&&-c / a <= x2)
			printf("%lld\n", y2 - y1 + 1);
		else
			printf("0\n");
	}
	else{
		if (a < 0)
			a *= -1;
		if (b < 0)
			b *= -1;
		if (c < 0)
			c *= -1;
		//ax+by=c
		//a<0 x -> -x
		//b<0 y -> -y
		//c<0 x, y-> -x, -y
		ll d = gcd(a, b);
		//as+bt=d
		//d|c true 해가 존재
		//d|c false 해가 없음
		if (c%d == 0){
			//해가 존재
			//특수해 x0=(c/d)s, y0=(c/d)t
			//일반해 x=x0+k(b/d), y=y0-k(a/d)
			if (xsign < 0){
				swap(x1, x2);
				x1 *= -1;
				x2 *= -1;
			}
			if (ysign < 0){
				swap(y1, y2);
				y1 *= -1;
				y2 *= -1;
			}
			ll x0 = (c / d)*s;
			ll y0 = (c / d)*t;
			ll bot, top;
			//x1 <= x0+k(b/d) <= x2
			//y1 <= y0-k(a/d) <= y2
			//(x1-x0)/(b/d) <= k <= (x2-x0)/(b/d)
			//(y0-y2)/(a/d) <= k <= (y0-y1)/(a/d)
			if ((x1 - x0) % (b / d) == 0)
				bot = (x1 - x0) / (b / d);
			else{
				bot = (x1 - x0) / (b / d);
				if ((x1-x0)>0)
					bot++;
			}
			if ((y0 - y2) % (a / d) == 0)
				bot = max(bot, (y0 - y2) / (a / d));
			else{
				if ((y0-y2)>0)
					bot = max(bot, (y0 - y2) / (a / d) + 1);
				else
					bot = max(bot, (y0 - y2) / (a / d));
			}
			if ((x2 - x0) % (b / d) == 0)
				top = (x2 - x0) / (b / d);
			else{
				top = (x2 - x0) / (b / d);
				if ((x2 - x0) < 0)
					top--;
			}
			if ((y0 - y1) % (a / d) == 0)
				top = min(top, (y0 - y1) / (a / d));
			else{
				if ((y0 - y1) < 0)
					top = min(top, (y0 - y1) / (a / d) - 1);
				else
					top = min(top, (y0 - y1) / (a / d));
			}
			if (bot>top)
				printf("0\n");
			else
				printf("%lld\n", top - bot + 1);
		}
		else
			printf("0\n");
	}
	return 0;
}
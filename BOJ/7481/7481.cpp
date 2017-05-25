// =====================================================================================
// 
//       Filename:  7481.cpp
//        Created:  2017년 05월 24일 18시 26분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, pair<ll, ll> > gcd(ll a, ll b){
	ll r[3];
	ll s[3];
	ll t[3];
	r[0]=a;
	r[1]=b;
	s[0]=1;
	s[1]=0;
	t[0]=0;
	t[1]=1;
	while(r[1]>0){
		ll q=r[0]/r[1];
		r[2]=r[0]-q*r[1];
		s[2]=s[0]-q*s[1];
		t[2]=t[0]-q*t[1];
		r[0]=r[1];
		r[1]=r[2];
		s[0]=s[1];
		s[1]=s[2];
		t[0]=t[1];
		t[1]=t[2];
	}
	return {r[0], {s[0], t[0]}};
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int a, b, s;
		scanf("%d%d%d", &a, &b, &s);
		bool flag=false;
		if(a>b){
			swap(a, b);
			flag=true;
		}
		if(s==0){
			printf("0 0\n");
			continue;
		}
		pair<ll, pair<ll, ll> > g=gcd(a, b);
		ll d=g.first;
		if(s%d!=0){
			printf("Impossible\n");
			continue;
		}
		ll x0=(s/d)*g.second.first;
		ll y0=(s/d)*g.second.second;
		//특수해
		//x=x0+k(b/d),  y=y0-k(a/d)
		ll k=0;
		if(x0<0)
			k=(-x0+b/d-1)/(b/d);
		else if(x0>0){
			k=x0/(b/d);
			k*=-1;
		}
		x0+=k*(b/d);
		y0-=k*(a/d);
		if(y0<0){
			printf("Impossible\n");
			continue;
		}
		if(flag)
			printf("%lld %lld\n", y0, x0);
		else
			printf("%lld %lld\n", x0, y0);
	}
	return 0;
}


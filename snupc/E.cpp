// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 09월 14일 21시 14분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{
	ll x, y;
	point(){}
	point(ll x, ll y):x(x), y(y){}
	point operator - (const point &rhs)const{
		return point(x-rhs.x, y-rhs.y);
	}
	ll cross(const point &rhs)const{
		return x*rhs.y-y*rhs.x;
	}
};
point arr[500000];
int n, m;
ll calc(int a, int b, int c){
	return abs((arr[b]-arr[a]).cross(arr[c]-arr[a]));
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%lld%lld", &arr[i].x, &arr[i].y);
	while(m--){
		ll x;
		scanf("%lld", &x);
		x*=2;
		ll s=0;
		for(int i=1;i+1<n;i++){
			s+=calc(0, i, i+1);
		}
		if(x==s){
			printf("%d %d\n", n, n);
			continue;
		}
		int cnt=2;
		int ed=1;
		s=0;
		int min_ans=0x3f3f3f3f;
		int max_ans=-1;
		for(int i=0;i<n;i++){
			while(s<x){
				int next=(ed+1)%n;
				s+=calc(i, ed, next);
				ed=next;
				cnt++;
			}
			min_ans=min(min_ans, cnt);
			max_ans=max(max_ans, cnt+1);
			s-=calc(i, i+1, ed);
			cnt--;
		}
		printf("%d %d\n", min_ans, max_ans);
	}
	return 0;
}


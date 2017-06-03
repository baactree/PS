// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 06월 03일 21시 07분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int h[100000];
typedef long long ll;
bool possi(ll x){
	ll diff=a-b;
	ll cnt=0;
	for(int i=0;i<n;i++){
		ll now=h[i]-x*b;
		if(now>0)
			cnt+=(now+diff-1)/diff;
	}
	return cnt<=x;	
}
int main(){
	scanf("%d%d%d", &n, &a, &b);
	for(int i=0;i<n;i++)
		scanf("%d", &h[i]);
	int le, ri, mid, ans;
	le=0;
	ri=1e9;
	ans=0;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%d\n", ans);
	return 0;
}


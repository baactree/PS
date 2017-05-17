// =====================================================================================
// 
//       Filename:  5415.cpp
//        Created:  2017년 05월 16일 19시 17분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
ll r[20];
ll d[20];
ll solve(ll x){
	if(x<=0)
		return 0;
	for(int i=15;i>0;i--){
		ll t=x/d[i];
		if(t!=0){
			ll ret=r[i];
			for(int j=1;j<t;j++){
				ret+=r[i];
				ret+=j*d[i];
			}
			ll k=x%d[i];
			ret+=t*(k+1);
			return ret+solve(k);
		}
	}
	return (x*(x+1))/2;
}
int main(){
	r[0]=0;
	d[0]=1;
	for(int i=1;i<16;i++)
		d[i]=d[i-1]*10;
	for(int i=1;i<16;i++)
		r[i]=r[i-1]*10+(45)*d[i-1];
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", solve(b)-solve(a-1));
	}
	return 0;
}


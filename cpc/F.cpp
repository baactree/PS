// =====================================================================================
// 
//       Filename:  F.cpp
//        Created:  2017년 09월 20일 19시 16분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n;
typedef long long ll;
ll _pow(int a, int b){
	if(b==0)
		return 1;
	ll temp=_pow(a, b/2);
	temp=(temp*temp)%mod;
	if(b&1)
		return (temp*a)%mod;
	return temp;
}
int main(){
	vector<pair<ll, int> > vec;
	int ans=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(b!=0){
			ans=(ans+((_pow(2, b-1)*a)%mod*b)%mod)%mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}


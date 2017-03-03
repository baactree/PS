// =====================================================================================
// 
//       Filename:  3079.cpp
//        Created:  2017년 01월 14일 20시 08분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
ll N, M;
ll arr[100000];

bool possi(ll x){
	ll ret=0;
	for(int i=0;i<N;i++){
		ret+=x/arr[i];
		ret=min(M, ret);
	}
	return ret>=M;
}

int main(){
	scanf("%lld%lld", &N, &M);
	for(int i=0;i<N;i++)
		scanf("%lld", &arr[i]);
	ll ans = inf;
	ll le , ri, mid;
	le=0;
	ri=inf;
	while(ri>=le){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%lld\n", ans);
	return 0;
}


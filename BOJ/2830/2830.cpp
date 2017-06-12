// =====================================================================================
// 
//       Filename:  2830.cpp
//        Created:  2017년 06월 12일 16시 34분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int bit[20];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		for(int j=0;j<20;j++){
			bit[j]+=in&1;
			in/=2;
		}
	}
	long long ans=0;
	for(int i=0;i<20;i++){
		ans+=(1ll<<i)*bit[i]*(n-bit[i]);
	}
	printf("%lld\n", ans);
	return 0;
}


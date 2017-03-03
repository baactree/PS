// =====================================================================================
// 
//       Filename:  4948.cpp
//        Created:  2017년 01월 17일 14시 44분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int prime[300000];
int cnt[300000];
int main(){
	memset(prime, -1, sizeof(prime));
	for(int i=2;i<=123456*2;i++){
		if(prime[i]==0)
			continue;
		prime[i]=1;
		for(int j=i+i;j<=123456*2;j+=i)
			prime[j]=0;
	}
	for(int i=2;i<=123456*2;i++){
		cnt[i]=cnt[i-1]+prime[i];
	}
	while(true){
		int n;
		scanf("%d", &n);
		if(n==0)
			break;
		printf("%d\n", cnt[2*n]-cnt[n]);
	}
	return 0;
}


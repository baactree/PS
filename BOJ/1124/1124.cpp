// =====================================================================================
// 
//       Filename:  1124.cpp
//        Created:  2017년 02월 25일 20시 21분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b;
int ans=0;
bool prime[100001];
bool isprime(int x){
	if(x==1)
		return false;
	if(x==2)
		return true;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)
			return false;
	}
	return true;
}
int solve(int x){
	int ret=0;
	if(x==2)
		return 0;
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
			ret++;
			x/=i;
		}
	}
	if(x!=1)
		ret++;
	return prime[ret];
}
int main(){
	for(int i=1;i<=100000;i++)
		prime[i]=isprime(i);
	scanf("%d%d", &a, &b);
	for(int i=a;i<=b;i++)
		ans+=solve(i);
	printf("%d\n", ans);
	return 0;
}


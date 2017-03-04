// =====================================================================================
// 
//       Filename:  2023.cpp
//        Created:  2017년 03월 04일 19시 58분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int prime[6]={1, 2, 3, 5, 7, 9};
int n;
bool isprime(int x){
	if(x==1)
		return false;
	if(x==2)
		return true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
void solve(int idx, int num){
	if(!isprime(num))
		return;
	if(idx==n){
		printf("%d\n", num);
		return;
	}
	for(int i=0;i<6;i++)
		solve(idx+1, num*10+prime[i]);
	return;
}

int main(){
	scanf("%d", &n);
	solve(0, 0);
	return 0;
}


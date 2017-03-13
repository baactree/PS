// =====================================================================================
// 
//       Filename:  1740.cpp
//        Created:  2017년 03월 13일 23시 06분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long int n;
int main(){
	scanf("%lld", &n);
	queue<int> q;
	while(n){
		q.push(n&1);
		n>>=1;
	}
	long long int ans=0;
	long long int r=1;
	while(!q.empty()){
		ans+=r*q.front();
		q.pop();
		r*=3;
	}
	printf("%lld\n", ans);
	return 0;
}


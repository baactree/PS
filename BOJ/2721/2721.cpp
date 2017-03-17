// =====================================================================================
// 
//       Filename:  2721.cpp
//        Created:  2017년 03월 15일 21시 38분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t(int x){
	return x*(x+1)/2;
}
ll w(int x){
	ll ret=0;
	for(ll i=1;i<=x;i++)
		ret+=i*t(i+1);
	return ret;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", w(n));
	}
	return 0;
}


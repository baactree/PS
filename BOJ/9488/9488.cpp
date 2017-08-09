// =====================================================================================
// 
//       Filename:  9488.cpp
//        Created:  2017년 08월 10일 01시 17분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll ans[1000005];
int main(){
	ll sum=0;
	for(int i=1;i<1000005;i++){
		sum+=i;
		ans[i]=ans[i-1]+sum;
	}
	while(scanf("%d", &n)){
		if(n==0)
			break;
		printf("%lld\n", ans[n]);
	}
	return 0;
}


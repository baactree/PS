// =====================================================================================
// 
//       Filename:  2553.cpp
//        Created:  2017년 03월 09일 20시 18분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		while(ans%10==0)
			ans/=10;
		ans=ans%10000000;
	}
	printf("%lld\n", ans%10);
	return 0;
}


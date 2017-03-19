// =====================================================================================
// 
//       Filename:  9546.cpp
//        Created:  2017년 03월 19일 18시 32분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int k;
		scanf("%d", &k);
		long long ans=0;
		while(k--){
			ans=ans*2+1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}


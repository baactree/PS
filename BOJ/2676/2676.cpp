// =====================================================================================
// 
//       Filename:  2676.cpp
//        Created:  2017년 05월 29일 21시 02분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d", &n, &m);
		if(m>n/2)
			m=n-m;
		int k=n-1;
		long long ans=1;
		while(m--){
			ans+=k;
			k-=2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}


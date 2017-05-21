// =====================================================================================
// 
//       Filename:  11815.cpp
//        Created:  2017년 05월 21일 13시 53분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		long long x;
		scanf("%lld", &x);
		long long t=sqrt(x);
		printf("%d ", (t*t)==x);
	}
	printf("\n");
	return 0;
}


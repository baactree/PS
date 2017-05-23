// =====================================================================================
// 
//       Filename:  11312.cpp
//        Created:  2017년 05월 23일 10시 44분 56초
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
		int a, b;
		scanf("%d%d", &a, &b);
		long long c=a/b;
		printf("%lld\n", c*c);
	}
	return 0;
}


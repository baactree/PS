// =====================================================================================
// 
//       Filename:  10093.cpp
//        Created:  2017년 03월 05일 18시 31분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main(){
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", b-a-1);
	for(long long i=a+1;i<b;i++)
		printf("%lld ", i);
	printf("\n");
	return 0;
}


// =====================================================================================
// 
//       Filename:  3474.cpp
//        Created:  2017년 09월 11일 23시 30분 39초
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
		int n;
		scanf("%d", &n);
		int k=n;
		int a=0;
		while(k){
			a+=k/2;
			k/=2;
		}
		int b=0;
		k=n;
		while(k){
			b+=k/5;
			k/=5;
		}
		printf("%d\n", min(a, b));
	}
	return 0;
}


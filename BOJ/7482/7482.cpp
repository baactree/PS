// =====================================================================================
// 
//       Filename:  7482.cpp
//        Created:  2017년 05월 19일 17시 36분 56초
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
		double a;
		scanf("%lf", &a);
		printf("%.10lf\n", a/6);
	}
	return 0;
}


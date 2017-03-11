// =====================================================================================
// 
//       Filename:  9469.cpp
//        Created:  2017년 03월 11일 19시 43분 19초
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
		int n;
		double d, a, b, f;
		scanf("%d%lf%lf%lf%lf", &n, &d, &a, &b, &f);
		printf("%d %.2lf\n", n, d/(a+b)*f);
	}
	return 0;
}


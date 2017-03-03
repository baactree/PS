// =====================================================================================
// 
//       Filename:  2783.cpp
//        Created:  2017년 03월 01일 13시 15분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	double v=(double)a/b;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d%d", &a, &b);
		double t=(double)a/b;
		v=min(v, t);
	}
	printf("%.2lf\n", v*1000);
	return 0;
}


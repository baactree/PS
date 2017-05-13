// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 05월 13일 18시 41분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, h;
double s;
int main(){
	scanf("%d%d", &n, &h);
	for(int i=1;i<n;i++)
		printf("%.10lf ", sqrt((i*(double)h*h)/n));
	printf("\n");
	return 0;
}


// =====================================================================================
// 
//       Filename:  2896.cpp
//        Created:  2017년 04월 28일 13시 30분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
double a[3];
double b[3];
int main(){
	scanf("%lf%lf%lf%lf%lf%lf", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	double m=min(a[0]/b[0], min(a[1]/b[1], a[2]/b[2]));
	a[0]-=b[0]*m;
	a[1]-=b[1]*m;
	a[2]-=b[2]*m;
	printf("%lf %lf %lf\n", a[0], a[1], a[2]);
	return 0;
}


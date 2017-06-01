// =====================================================================================
// 
//       Filename:  14583.cpp
//        Created:  2017년 06월 02일 02시 13분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
double h, v;
int main(){
	scanf("%lf%lf", &h, &v);
	double theta=atan2(v, h);
	double w=hypot(h, v);
	printf("%.2lf %.2lf\n", h/cos(theta/2)/2, w*sin(theta/2));
	return 0;
}


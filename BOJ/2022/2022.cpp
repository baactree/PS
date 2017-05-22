// =====================================================================================
// 
//       Filename:  2022.cpp
//        Created:  2017년 05월 22일 13시 59분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
double x, y, c;
bool possi(double m){
	double a, b;
	a=sqrt(x*x-m*m);
	b=sqrt(y*y-m*m);
	return c<=((a*b)/(a+b));
}
int main(){
	while(scanf("%lf%lf%lf", &x, &y, &c)!=EOF){
		double ans;
		double le, ri, mid;
		le=0;
		ri=min(x, y);
		int cnt=0;
		while(cnt<60){
			mid=(le+ri)/2;
			if(possi(mid)){
				ans=mid;
				le=mid;
			}
			else
				ri=mid;
			cnt++;
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}


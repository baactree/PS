// =====================================================================================
// 
//       Filename:  1069.cpp
//        Created:  2017년 06월 14일 01시 29분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long x, y, d, t;
int main(){
	while(scanf("%lld%lld%lld%lld", &x, &y, &d, &t)!=EOF){
		long double r=hypot(x, y);
		long double ans=r;
		ans=min(ans, t+abs(r-d));
		for(long long i=2;i<2005;i++){
			if(i*d>r)
				ans=min(ans, (long double)t*i);
			else
				ans=min(ans, t*i+r-d*i);
		}
		printf("%.10Lf\n", ans);
	}
	return 0;
}


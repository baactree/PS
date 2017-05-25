// =====================================================================================
// 
//       Filename:  1166.cpp
//        Created:  2017년 05월 24일 17시 37분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, l, w, h;
bool possi(long double x){
	int a=l/x;
	int b=w/x;
	int c=h/x;
	return min((long long)n, (long long)a*b)*(long long)c>=n;
}
int main(){
	scanf("%d%d%d%d", &n, &l, &w, &h);
	long double le, ri, mid;
	le=0;
	ri=1e9;
	int cnt=0;
	while(cnt<10000){
		cnt++;
		mid=(le+ri)/2.;
		if(possi(mid)){
			le=mid;
		}
		else
			ri=mid;
	}
	printf("%.12Lf\n", le);
	return 0;
}


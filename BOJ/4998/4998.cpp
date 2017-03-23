// =====================================================================================
// 
//       Filename:  4998.cpp
//        Created:  2017년 03월 23일 11시 47분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
double n, m, b;
bool possi(int x){
	return n*(pow(b, x))>=m;
}
int main(){
	while(scanf("%lf%lf%lf", &n, &b, &m)!=EOF){
		b/=100;
		b+=1;
		int le, ri, mid, ans;
		le=0;
		ri=1e9;
		while(le<=ri){
			mid=(le+ri)/2;
			if(possi(mid)){
				ans=mid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		printf("%d\n", ans);
	}
	return 0;
}


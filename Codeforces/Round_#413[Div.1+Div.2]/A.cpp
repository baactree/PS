// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 05월 22일 22시 52분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, t, k, d;
int main(){
	scanf("%d%d%d%d", &n, &t, &k, &d);
	int a, b;
	a=(n+k-1)/k*t;
	for(int i=1;;i++){
		if(i%t==0)
			n-=k;
		if(i-d>0&&(i-d)%t==0)
			n-=k;
		if(n<=0){
			b=i;
			break;
		}
	}
	printf("%s\n", (a>b?"YES":"NO"));
	return 0;
}


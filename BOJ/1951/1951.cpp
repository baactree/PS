// =====================================================================================
// 
//       Filename:  1951.cpp
//        Created:  2017년 05월 02일 01시 28분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	int ans=0;
	for(int i=9;i>=0;i--){
		int r=1;
		for(int j=0;j<i;j++)
			r*=10;
		if(n>=r){
			n-=r-1;
			ans+=((i+1ll)*n)%1234567;
			ans%=1234567;
			n=r-1;
		}
	}
	printf("%d\n", ans);
	return 0;
}


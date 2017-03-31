// =====================================================================================
// 
//       Filename:  2622.cpp
//        Created:  2017년 03월 31일 17시 49분 33초
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
	if(n==1||n==2||n==4){
		printf("0\n");
		return 0;
	}
	int ans=0;
	if(n&1){
		for(int i=(n-1)/2;i>=1&&i>=ceil((n-i)/2.);i--){
			int temp=n-i;
			ans+=temp/2-(temp-i-1);
		}
	}
	else{
		for(int i=(n-2)/2;i>=1&&i>=ceil((n-i)/2.);i--){
			int temp=n-i;
			ans+=temp/2-(temp-i-1);
		}
	}
	printf("%d\n", ans);
	return 0;
}


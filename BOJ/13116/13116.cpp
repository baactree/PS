// =====================================================================================
// 
//       Filename:  13116.cpp
//        Created:  2017년 06월 10일 14시 41분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dep[1024];
int lca(int a, int b){
	if(dep[b]>dep[a])
		swap(a, b);
	while(dep[b]!=dep[a])
		a/=2;
	while(a!=b){
		a/=2;
		b/=2;
	}
	return a;
}
int main(){
	int r1=1;
	int r2=2;
	for(int i=0;i<10;i++){
		for(int j=r1;j<r2;j++)
			dep[j]=i;
		r1*=2;
		r2*=2;
	}
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", lca(a, b)*10);
	}
	return 0;
}


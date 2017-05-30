// =====================================================================================
// 
//       Filename:  9468.cpp
//        Created:  2017년 05월 30일 22시 30분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[15];
int solve(int le, int ri, int dep){
	if(le==ri)
		return 0;
	int ret=0;
	int st, fi;
	st, fi=0;
	for(int i=le+1;i<ri;i++){
		if(arr[i-1]<=dep){
			st=i;
		}
		if(arr[i]>dep&&arr[i+1]<=dep){
			ret+=solve(st, i, dep+1)+1;
		}
	}
	return ret;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	n=15;
	while(testcase--){
		int k;
		scanf("%d", &k);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		printf("%d %d\n", k, solve(0, 14, 0));
	}
	return 0;
}


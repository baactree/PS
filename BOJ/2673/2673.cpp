// =====================================================================================
// 
//       Filename:  2673.cpp
//        Created:  2017년 04월 28일 13시 13분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[105][105];
int cache[105][105];
int solve(int le, int ri){
	if(le>=ri)
		return 0;
	int &ret=cache[le][ri];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int k=le;k<=ri;k++)
		ret=max(ret, solve(le, k)+solve(k+1, ri));
	return ret=ret+arr[le][ri];
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a][b]=arr[b][a]=1;
	}
	printf("%d\n", solve(1, 100));
	return 0;
}


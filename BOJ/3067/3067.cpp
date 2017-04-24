// =====================================================================================
// 
//       Filename:  3067.cpp
//        Created:  2017년 04월 25일 00시 21분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[20];
int cache[20][10005];
int solve(int idx, int k){
	if(k>m)
		return 0;
	if(idx==n){
		if(k==m)
			return 1;
		return 0;
	}
	int &ret=cache[idx][k];
	if(ret!=-1)
		return ret;
	ret=0;
	ret+=solve(idx, k+arr[idx]);
	ret+=solve(idx+1, k);
	return ret;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		scanf("%d", &m);
		printf("%d\n", solve(0, 0));
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  2629.cpp
//        Created:  2017년 03월 02일 14시 16분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cache[30][50000];
int n;
int arr[30];
int solve(int idx, int m){
	if(m==0)
		return 1;
	if(idx==n)
		return 0;
	int &ret=cache[idx][m+25000];
	if(ret!=-1)
		return ret;
	ret = solve(idx+1, m);
	ret |= solve(idx+1, m+arr[idx]);
	ret |= solve(idx+1, m-arr[idx]);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	int q;
	scanf("%d", &q);
	for(int i=0;i<q;i++){
		int in;
		scanf("%d", &in);
		if(in>sum){
			printf("N ");
			continue;
		}
		if(solve(0, in)){
			printf("Y ");
		}
		else
			printf("N ");
	}
	printf("\n");
	return 0;
}


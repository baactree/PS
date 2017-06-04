// =====================================================================================
// 
//       Filename:  2253.cpp
//        Created:  2017년 06월 04일 18시 49분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10005];
int inf=0x3f3f3f3f;
int cache[10005][305];
int solve(int idx, int step){
	if(idx>n)
		return inf;
	if(arr[idx])
		return inf;
	if(idx==n)
		return 0;
	int &ret=cache[idx][step];
	if(ret!=-1)
		return ret;
	ret=solve(idx+step+1, step+1)+1;
	if(step>0)
		ret=min(ret, solve(idx+step, step)+1);
	if(step-1>0)
		ret=min(ret, solve(idx+step-1, step-1)+1);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		arr[in]=true;
	}
	int ans=solve(1, 0);
	printf("%d\n", ans>=inf?-1:ans);
	return 0;
}


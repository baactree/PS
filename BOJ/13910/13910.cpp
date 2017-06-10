// =====================================================================================
// 
//       Filename:  13910.cpp
//        Created:  2017년 06월 10일 13시 44분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100];
int cache[10005];
const int inf=0x3f3f3f3f;
int solve(int idx){
	if(idx<0)
		return inf;
	if(idx==0)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=inf;
	for(int i=0;i<m;i++)
		ret=min(ret, solve(idx-arr[i])+1);
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			ret=min(ret, solve(idx-arr[i]-arr[j])+1);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++)
		scanf("%d", &arr[i]);
	int ans=solve(n);
	printf("%d\n", ans==inf?-1:ans);
	return 0;
}


// =====================================================================================
// 
//       Filename:  2449.cpp
//        Created:  2017년 05월 08일 16시 51분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[200];
int cache[200][200][21];
int solve(int le, int ri, int col){
	if(le>ri)
		return 0;
	int &ret=cache[le][ri][col];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	if(arr[le]==arr[ri]){
		int lidx=le+1;
		while(lidx<n&&arr[lidx]==arr[le])
			lidx++;
		int ridx=ri-1;
		while(ridx>=0&&arr[ridx]==arr[ri])
			ridx--;
		ret=min(ret, solve(lidx, ridx, arr[le])+(arr[le]!=col?1:0));
	}
	else{
		for(int idx=le;idx<ri;idx++)
			ret=min(ret, solve(le, idx, col)+solve(idx+1, ri, col));
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int ans=0x3f3f3f3f3f;
	for(int i=1;i<=k;i++)
		ans=min(ans, solve(0, n-1, i));
	printf("%d\n", ans);
	return 0;
}


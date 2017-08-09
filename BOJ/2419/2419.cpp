// =====================================================================================
// 
//       Filename:  2419.cpp
//        Created:  2017년 08월 09일 13시 26분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[305];
int cache[305][305][2];
int solve(int cnt, int le, int ri, int mode){
	if(cnt==0)
		return 0;
	int &ret=cache[le][ri][mode];
	if(ret!=0xcccccccc)
		return ret;
	int lidx=le-1;
	int ridx=ri+1;
	if(lidx>=0){
		if(mode){
			int dist=arr[ri]-arr[lidx];
			ret=max(ret, m+solve(cnt-1, lidx, ri, 0)-cnt*dist);
		}
		else{
			int dist=arr[le]-arr[lidx];
			ret=max(ret, m+solve(cnt-1, lidx, ri, 0)-cnt*dist);
		}
	}
	if(ridx<n){
		if(mode){
			int dist=arr[ridx]-arr[ri];
			ret=max(ret, m+solve(cnt-1, le, ridx, 1)-cnt*dist);
		}
		else{
			int dist=arr[ridx]-arr[le];
			ret=max(ret, m+solve(cnt-1, le, ridx, 1)-cnt*dist);
		}
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	bool flag=false;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		if(arr[i]==0)
			flag=true;
	}
	if(!flag)
		arr[n++]=0;
	sort(arr, arr+n);
	int st=-1;
	for(int i=0;i<n;i++)
		if(arr[i]==0)
			st=i;
	int ans=0;
	for(int i=0;i<n;i++){
		memset(cache, 0xcc, sizeof(cache));
		ans=max(ans, solve(i, st, st, 0)+(flag?m:0));
	}
	printf("%d\n", ans);
	return 0;
}


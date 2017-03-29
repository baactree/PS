// =====================================================================================
// 
//       Filename:  2457.cpp
//        Created:  2017년 03월 28일 23시 25분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int m[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day[13][35];
int n;
struct F{
	int a, b, c, d;
	bool operator < (const F &rhs)const{
		if(a==rhs.a){
			if(b==rhs.b){
				if(c==rhs.c){
					return d<rhs.d;
				}
				return c<rhs.c;
			}
			return b<rhs.b;
		}
		return a<rhs.a;
	}
};
F arr[100000];
//int cache[100000][400];
/*
int solve(int idx, int f){
	if(f>=day[11][30])
		return 0;
	if(idx==n)
		return 0x3f3f3f3f;
	int &ret=cache[idx][f];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1, f);
	if(day[arr[idx].a][arr[idx].b]<=f)
		ret=min(ret, solve(idx+1, day[arr[idx].c][arr[idx].d])+1);
	return ret;
}
*/
int dp[2][400];
int main(){
	for(int i=1;i<=12;i++){
		day[i][0]=day[i-1][m[i-1]]+1;
		for(int j=1;j<=m[i];j++)
			day[i][j]=day[i][j-1]+1;
	}
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c, &arr[i].d);
	//memset(cache, -1, sizeof(cache));
	sort(arr, arr+n);
	//int ans=solve(0, day[2][28]);

	memset(dp, 0x3f, sizeof(dp));
	dp[0][day[3][1]]=0;
	int ans2=0x3f3f3f3f;
	for(int i=0;i<n;i++){
		for(int j=0;j<400;j++){
			dp[(i+1)&1][j]=min(dp[(i+1)&1][j], dp[i&1][j]);
			if(day[arr[i].a][arr[i].b]<=j){
				dp[(i+1)&1][day[arr[i].c][arr[i].d]]=min(dp[(i+1)&1][day[arr[i].c][arr[i].d]], dp[i&1][j]+1);
			}
		}
	}
	for(int i=day[12][1];i<400;i++)
		ans2=min(ans2, dp[n&1][i]);
	//printf("%d\n", ans==0x3f3f3f3f?0:ans);
	printf("%d\n", ans2==0x3f3f3f3f?0:ans2);
	return 0;
}


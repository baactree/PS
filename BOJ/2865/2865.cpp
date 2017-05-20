// =====================================================================================
// 
//       Filename:  2865.cpp
//        Created:  2017년 05월 20일 11시 49분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
double cache[100][105];
int n, m, k;
double arr[100];
double solve(int idx, int cnt){
	if(idx==n){
		if(cnt==k)
			return 0;
		return -1e9;
	}
	double &ret=cache[idx][cnt];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1, cnt);
	if(cnt<k)
		ret=max(ret, solve(idx+1, cnt+1)+arr[idx]);
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<n;i++)
		arr[i]=-1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=k;j++)
			cache[i][j]=-1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int a;
			double b;
			scanf("%d%lf", &a, &b);
			arr[a-1]=max(arr[a-1], b);
		}
	}
	printf("%.1lf\n", solve(0, 0));
	return 0;
}


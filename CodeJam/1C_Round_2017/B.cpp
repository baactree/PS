// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 04월 30일 18시 25분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100];
pair<int, int> b[100];
int arr[1441];
int cache[1500][1000][3][3];
int solve(int idx, int cnt, int front, int pre){
	if(cnt>720)
		return 0x3f3f3f3f;
	if(idx==1440){
		if(cnt==720){
			if(front==pre)
				return 0;
			return 1;
		}
		return 0x3f3f3f3f;
	}
	int &ret=cache[idx][cnt][front][pre];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	if(arr[idx]==1){
		if(idx==0)
			ret=min(ret, solve(idx+1, cnt, 2, 2));
		else
			ret=min(ret, solve(idx+1, cnt, front, 2)+(pre==2?0:1));
	}
	if(arr[idx]==2){
		if(idx==0)
			ret=min(ret, solve(idx+1, cnt+1, 1, 1));
		else
			ret=min(ret, solve(idx+1, cnt+1, front, 1)+(pre==1?0:1));
	}
	if(arr[idx]==0){
		if(idx==0){
			ret=min(ret, solve(idx+1, cnt+1, 1, 1));
			ret=min(ret, solve(idx+1, cnt, 2, 2));
		}
		else{
			ret=min(ret, solve(idx+1, cnt+1, front, 1)+(pre==1?0:1));
			ret=min(ret, solve(idx+1, cnt, front, 2)+(pre==2?0:1));
		}
	}
	return ret;
}
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		int n, m;
		scanf("%d%d", &n, &m);
		memset(arr, 0, sizeof(arr));
		for(int i=0;i<n;i++){
			scanf("%d%d", &a[i].first, &a[i].second);
			for(int j=a[i].first;j<a[i].second;j++)
				arr[j]=1;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d", &b[i].first, &b[i].second);
			for(int j=b[i].first;j<b[i].second;j++)
				arr[j]=2;
		}
		memset(cache, -1, sizeof(cache));
		printf("Case #%d: %d\n",tc,  solve(0, 0, 0, 0));
	}
	return 0;
}


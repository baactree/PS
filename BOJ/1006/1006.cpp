// =====================================================================================
// 
//       Filename:  1006.cpp
//        Created:  2017년 04월 07일 17시 33분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, w;
pair<int, int> arr[10000];
int cache[10000][4][3];
int solve(int idx, int zero, int state){
	if(idx==n)
		return 0;
	if(idx==n-1&&zero>0){
		if(state==0)
			return zero!=3;
		if(state==1)
			return zero==1;
		if(state==2)
			return zero==2;
	}

	int &ret=cache[idx][zero][state];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;

	if(idx==0){
		if(arr[idx].first+arr[n-1].first<=w&&arr[idx].second+arr[n-1].second<=w)
			ret=min(ret, solve(idx+1, 3, 0)+2);
		if(arr[idx].first+arr[n-1].first<=w){
			ret=min(ret, solve(idx+1, 1, 0)+2);
			if(idx+1<n&&arr[idx].second+arr[idx+1].second<=w)
				ret=min(ret, solve(idx+1, 1, 2)+2);
		}
		if(arr[idx].second+arr[n-1].second<=w){
			ret=min(ret, solve(idx+1, 2, 0)+2);
			if(idx+1<n&&arr[idx].first+arr[idx+1].first<=w)
				ret=min(ret, solve(idx+1, 2, 1)+2);
		}
	}
	
	if(state==0){
		ret=min(ret, solve(idx+1, zero, 0)+2);
		if(arr[idx].first+arr[idx].second<=w)
			ret=min(ret, solve(idx+1, zero, 0)+1);
		if(idx+1+(zero!=0)<n&&arr[idx].first+arr[idx+1].first<=w&&arr[idx].second+arr[idx+1].second<=w)
			ret=min(ret, solve(idx+2, zero, 0)+2);
		if(idx+1+(zero==1||zero==3)<n&&arr[idx].first+arr[idx+1].first<=w)
			ret=min(ret, solve(idx+1, zero, 1)+2);
		if(idx+1+(zero==2||zero==3)<n&&arr[idx].second+arr[idx+1].second<=w)
			ret=min(ret, solve(idx+1, zero, 2)+2);
	}
	if(state==1){
		ret=min(ret, solve(idx+1, zero, 0)+1);
		if(idx+1+(zero==2||zero==3)<n&&arr[idx].second+arr[idx+1].second<=w)
			ret=min(ret, solve(idx+1, zero, 2)+1);
	}
	if(state==2){
		ret=min(ret, solve(idx+1, zero, 0)+1);
		if(idx+1+(zero==1||zero==3)<n&&arr[idx].first+arr[idx+1].first<=w)
			ret=min(ret, solve(idx+1, zero, 1)+1);
	}

	return ret;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d", &n, &w);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i].first);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i].second);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}


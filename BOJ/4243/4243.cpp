// =====================================================================================
// 
//       Filename:  4243.cpp
//        Created:  2017년 04월 23일 22시 36분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int st;
long long arr[105];
long long cache[105][105][2];
long long dist[105];
long long solve(int le, int ri, int mode, int cnt){
	if(cnt==0)
		return 0;
	long long &ret=cache[le][ri][mode];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f3f3f3f3f;
	if(mode){
		if(ri!=n)
			ret=min(ret, solve(le, ri+1, mode, cnt-1)+arr[ri]*cnt);
		if(le!=1)
			ret=min(ret, solve(le-1, ri, 0, cnt-1)+(dist[ri-1]-dist[le-2])*cnt);
	}
	else{
		if(ri!=n)
			ret=min(ret, solve(le, ri+1, 1, cnt-1)+(dist[ri]-dist[le-1])*cnt);
		if(le!=1)
			ret=min(ret, solve(le-1, ri, 0, cnt-1)+arr[le-1]*cnt);
	}
	return ret;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		scanf("%d", &st);
		for(int i=1;i<n;i++)
			scanf("%lld", &arr[i]);
		for(int i=1;i<n;i++)
			dist[i]=dist[i-1]+arr[i];
		printf("%lld\n", solve(st, st, 0, n-1));
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  9440.cpp
//        Created:  2017년 05월 26일 00시 10분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[14];
typedef long long ll;
ll r[15];
ll cache[1<<14][14][2][2];
const ll inf=0x3f3f3f3f3f3f3f3f;
ll solve(int idx, int state, int aidx, int bidx, int apre, int bpre){
	if(idx==n){
		if(apre||bpre)
			return inf;
		return 0;
	}
	ll &ret=cache[state][aidx][apre][bpre];
	if(ret!=-1)
		return ret;
	ret=inf;
	for(int i=0;i<n;i++)
		if(!(state&(1<<i))){
			ret=min(ret, solve(idx+1, state|(1<<i), aidx+1, bidx, arr[i]==0, bpre)+r[aidx]*arr[i]);
			ret=min(ret, solve(idx+1, state|(1<<i), aidx, bidx+1, apre, arr[i]==0)+r[bidx]*arr[i]);
		}
	return ret;
}

int main(){	
	r[0]=1;
	for(int i=1;i<15;i++)
		r[i]=r[i-1]*10;
	while(true){
		memset(cache, -1, sizeof(cache));
		scanf("%d", &n);
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		printf("%lld\n", solve(0, 0, 0, 0, 0, 0));
	}

	return 0;
}


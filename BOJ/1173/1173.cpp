// =====================================================================================
// 
//       Filename:  1173.cpp
//        Created:  2017년 03월 20일 18시 57분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, M, t, r;
int cache[205][205];
int solve(int idx, int now){
	if(idx==n)
		return 0;
	int &ret=cache[idx][now];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	if(now+t<=M)
		ret=min(ret, solve(idx+1, now+t)+1);
	ret=min(ret, solve(idx, max(m, now-r))+1);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d%d%d%d", &n, &m, &M, &t, &r);
	int ans=solve(0, m);
	printf("%d\n", ans==0x3f3f3f3f?-1:ans);
	return 0;
}


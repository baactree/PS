// =====================================================================================
// 
//       Filename:  2305.cpp
//        Created:  2017년 07월 30일 21시 33분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int cache[50][2][2][2];
int solve(int idx, int pre, int now, int f){
	if(idx==n)
		return 1;
	int &ret=cache[idx][pre][now][f];
	if(ret!=-1)
		return ret;
	if(idx==k)
		return ret=solve(idx+1, 1, 0, f);
	ret=0;
	if(f==0)
		ret+=solve(idx+1, now, 0, 1);
	if(now==0)
		ret+=solve(idx+1, 1, 0, f);
	if(idx+1!=k&&idx+1!=n)
		ret+=solve(idx+1, now, 1, f);
	if(pre==0)
		ret+=solve(idx+1, now, 0, f);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &k);
	k--;
	printf("%d\n", solve(0, 1, 0, 0));
	return 0;
}


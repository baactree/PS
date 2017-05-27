// =====================================================================================
// 
//       Filename:  9764.cpp
//        Created:  2017년 05월 27일 17시 09분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int mod=100999;
int cache[2005][2005];
int n;
int solve(int idx, int num){
	if(num==0)
		return 1;
	if(idx>num||num<0)
		return 0;
	int &ret=cache[idx][num];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1, num-idx);
	ret+=solve(idx+1, num);
	ret%=mod;
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		printf("%d\n", solve(1, n));
	}
	return 0;
}


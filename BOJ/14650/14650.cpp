// =====================================================================================
// 
//       Filename:  14650.cpp
//        Created:  2017년 08월 03일 02시 36분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int cache[10][30];
int solve(int idx, int sum){
	if(idx==n)
		return sum%3==0;
	int &ret=cache[idx][sum];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<3;i++){
		if(idx==0&&i==0)
			continue;
		ret+=solve(idx+1, sum+i);
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	printf("%d\n", solve(0, 0));
	return 0;
}


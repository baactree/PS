// =====================================================================================
// 
//       Filename:  14501.cpp
//        Created:  2017년 04월 23일 20시 24분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[15];
int cache[15];
int solve(int idx){
	if(idx>n)
		return -0x3f3f3f3f;
	if(idx==n)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1);
	ret=max(solve(idx+arr[idx].first)+arr[idx].second, ret);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	printf("%d\n", solve(0));
	return 0;
}


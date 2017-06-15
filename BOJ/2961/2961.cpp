// =====================================================================================
// 
//       Filename:  2961.cpp
//        Created:  2017년 06월 15일 04시 32분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[10];
long long solve(int idx, long long s, long long c, int p){
	if(idx==n){
		if(!p||s>=1e13)
			return 1e18;
		return abs(s-c);
	}
	long long ret=solve(idx+1, s, c, p);
	if(log(s)+log(arr[idx].first)<18)
		ret=min(ret, solve(idx+1, s*arr[idx].first, c+arr[idx].second, 1));
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	printf("%lld\n", solve(0, 1, 0, 0));
	return 0;
}


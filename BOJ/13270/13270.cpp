// =====================================================================================
// 
//       Filename:  13270.cpp
//        Created:  2017년 08월 03일 14시 02분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dp[1000];
int n;
vector<pair<int, int> >  vec;
vector<int> cache;
const int inf=0x3f3f3f3f;
int solve1(int idx){
	if(idx>n)
		return inf;
	if(idx==n)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=inf;
	for(int i=0;i<vec.size();i++)
		ret=min(ret, solve1(idx+vec[i].first)+vec[i].second);
	return ret;
}
int solve2(int idx){
	if(idx>n)
		return -inf;
	if(idx==n)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<vec.size();i++)
		ret=max(ret, solve2(idx+vec[i].first)+vec[i].second);
	return ret;
}
int main(){
	scanf("%d", &n);
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<30;i++){
		dp[i]=dp[i-1]+dp[i-2];
		vec.push_back({dp[i], dp[i-1]});
	}
	cache=vector<int>(n, -1);
	printf("%d ", solve1(0));
	cache=vector<int>(n, -1);
	printf("%d\n", solve2(0));
	return 0;
}


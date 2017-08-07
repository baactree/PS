// =====================================================================================
// 
//       Filename:  12019.cpp
//        Created:  2017년 08월 08일 02시 31분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[100];
int cache[100][11][2005];
vector<int> ans;
int solve(int idx, int cnt, int d){
	if(idx==n)
		return 0;
	int &ret=cache[idx][cnt][d];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	if(cnt<m)
		ret=min(ret, solve(idx+1, cnt+1, 0)+p[idx]*d);
	ret=min(ret, solve(idx+1, cnt, d+p[idx])+p[idx]*d);
	return ret;
}
void get_ans(int idx, int cnt, int d){
	if(idx==n)
		return;
	int a, b;
	a=b=0x3f3f3f3f;
	if(cnt<m)
		a=solve(idx+1, cnt+1, 0)+p[idx]*d;
	b=solve(idx+1, cnt, d+p[idx])+p[idx]*d;
	if(a<=b){
		ans.push_back(idx+1);
		get_ans(idx+1, cnt+1, 0);
		return;
	}
	get_ans(idx+1, cnt, d+p[idx]);
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d", &p[i]);
	printf("%d\n", solve(0, 0, 0));
	get_ans(0, 0, 0);
	for(auto x:ans)
		printf("%d ", x);
	printf("\n");
	return 0;
}


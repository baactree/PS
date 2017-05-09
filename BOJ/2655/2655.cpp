// =====================================================================================
// 
//       Filename:  2655.cpp
//        Created:  2017년 05월 08일 16시 40분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int s, h, w, idx;
	bool operator < (const Node &rhs)const{
		return s>rhs.s;
	}
};
int n;
Node arr[100];
int cache[100][11000];
vector<int> ans;
int solve(int idx, int pre){
	if(idx==n)
		return 0;
	int &ret=cache[idx][pre];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1, pre);
	if(arr[idx].w<pre)
		ret=max(ret, solve(idx+1, arr[idx].w)+arr[idx].h);
	return ret;
}
void get_ans(int idx, int pre){
	if(idx==n)
		return ;
	int a, b;
	a=b=-1;
	a=solve(idx+1, pre);
	if(arr[idx].w<pre)
		b=solve(idx+1, arr[idx].w)+arr[idx].h;
	if(a<b){
		ans.push_back(arr[idx].idx);
		get_ans(idx+1, arr[idx].w);
	}
	else
		get_ans(idx+1, pre);
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d", &arr[i].s, &arr[i].h, &arr[i].w);
		arr[i].idx=i+1;
	}
	sort(arr, arr+n);
	solve(0, 10001);
	get_ans(0, 10001);
	printf("%d\n", ans.size());
	for(int i=ans.size()-1;i>=0;i--)
		printf("%d\n", ans[i]);
	return 0;
}


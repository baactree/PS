// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 04월 29일 02시 04분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
char str[1005];
int cache[1005][2005];
int solve(int idx, int t){
	if(idx==n){
		return abs(t)==k;
	}
	if(abs(t)==k)
		return 0;
	int &ret=cache[idx][t+1002];
	if(ret!=-1)
		return ret;
	if(str[idx]=='W'){
		return ret=solve(idx+1, t+1);
	}
	if(str[idx]=='L'){
		return ret=solve(idx+1, t-1);
	}
	if(str[idx]=='D'){
		return ret=solve(idx+1, t);
	}
	ret=0;
	ret|=solve(idx+1, t+1);
	ret|=solve(idx+1, t);
	ret|=solve(idx+1, t-1);
	return ret;
}
void get_ans(int idx, int t){
	if(idx==n){
		return;
	}
	if(str[idx]=='W'){
		get_ans(idx+1, t+1);
		return;
	}
	if(str[idx]=='L'){
		get_ans(idx+1, t-1);
		return;
	}
	if(str[idx]=='D'){
		get_ans(idx+1, t);
		return;
	}
	int a, b, c;
	a=solve(idx+1, t+1);
	b=solve(idx+1, t);
	c=solve(idx+1, t-1);
	if(a){
		str[idx]='W';
		get_ans(idx+1, t+1);
		return;
	}
	if(b){
		str[idx]='D';
		get_ans(idx+1, t);
		return;
	}
	if(c){
		str[idx]='L';
		get_ans(idx+1, t-1);
		return;
	}
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &k);
	scanf("%s", str);
	int ans=solve(0, 0);
	if(ans==0){
		printf("NO\n");
		return 0;
	}
	get_ans(0, 0);
	printf("%s\n", str);
	return 0;
}


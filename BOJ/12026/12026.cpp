// =====================================================================================
// 
//       Filename:  12026.cpp
//        Created:  2017년 05월 20일 11시 33분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char str[1005];
int cache[1005];
const int inf=0x3f3f3f3f;
int solve(int idx){
	if(idx==n-1)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=inf;
	char next=0;
	if(str[idx]=='B')
		next='O';
	else if(str[idx]=='O')
		next='J';
	else
		next='B';
	for(int i=idx+1;i<n;i++)
		if(str[i]==next){
			int k=i-idx;
			ret=min(ret, solve(i)+k*k);
		}
	return ret;
}
int main(){
	scanf("%d", &n);
	scanf("%s", str);
	memset(cache, -1, sizeof(cache));
	int ans=solve(0);
	printf("%d\n", ans==inf?-1:ans);
	return 0;
}


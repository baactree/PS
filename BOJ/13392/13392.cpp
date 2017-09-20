// =====================================================================================
// 
//       Filename:  13392.cpp
//        Created:  2017년 09월 19일 00시 36분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int cache[10000][10];
int st[10000];
int ed[10000];
int solve(int idx, int lot){
	if(idx==n)
		return 0;
	int &ret=cache[idx][lot];
	if(ret!=-1)
		return ret;
	int now=(st[idx]+lot)%10;
	ret=solve(idx+1, lot)+(now-ed[idx]+10)%10;
	int cnt=(ed[idx]-now+10)%10;
	ret=min(ret, solve(idx+1, (lot+cnt)%10)+cnt);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%1d", &st[i]);
	for(int i=0;i<n;i++)
		scanf("%1d", &ed[i]);
	printf("%d\n", solve(0, 0));
	return 0;
}


// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 19일 23시 28분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, x;
int cnt[105];

int main(){
	scanf("%d%d", &n, &x);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		cnt[in]=1;
	}
	int ans=0;
	for(int i=0;i<x;i++){
		if(!cnt[i])
			ans++;
	}
	if(cnt[x])
		ans++;
	printf("%d\n", ans);
	return 0;
}


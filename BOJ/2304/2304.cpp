// =====================================================================================
// 
//       Filename:  2304.cpp
//        Created:  2017년 05월 03일 15시 06분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int h[1001];
int maxhl[1002];
int maxhr[1002];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		h[a]=b;
	}
	for(int i=1;i<=1000;i++)
		maxhl[i]=max(maxhl[i-1], h[i]);
	for(int i=1000;i>=1;i--)
		maxhr[i]=max(maxhr[i+1], h[i]);
	int ans=0;
	for(int i=1;i<=1000;i++)
		ans+=min(maxhl[i], maxhr[i]);
	printf("%d\n", ans);
	return 0;
}


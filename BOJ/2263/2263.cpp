// =====================================================================================
// 
//       Filename:  2263.cpp
//        Created:  2017년 03월 17일 18시 36분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000];
int b[100000];
int c[100000];
int k[100001];
int idx;
void solve(int al, int ar, int bl, int br){
	if(al>ar)
		return;
	c[idx++]=b[br];
	int tt=k[b[br]];
	int cnt=tt-al;
	solve(al, tt-1, bl, bl+cnt-1);
	solve(tt+1, ar, bl+cnt, br-1);
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
		k[a[i]]=i;
	}
	for(int i=0;i<n;i++)
		scanf("%d", &b[i]);
	solve(0, n-1,0, n-1);
	for(int i=0;i<n;i++)
		printf("%d ", c[i]);
	return 0;
}


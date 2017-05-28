// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 05월 27일 18시 39분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> p;
int cnt[10005];
int t[10005];
int main(){
	scanf("%d%d", &n, &m);
	p.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d", &p[i]);
	for(int i=0;i<m;i++){
		int a, b, x;
		scanf("%d%d%d", &a, &b, &x);
		a--;
		b--;
		for(int j=0;j<=n;j++)
			cnt[j]=0;
		for(int j=a;j<=b;j++)
			cnt[p[j]]++;
		int idx=0;
		for(int j=0;j<=n;j++)
			for(int k=0;k<cnt[j];k++)
				t[idx++]=j;
		if(t[x-1-a]==p[x-1])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}


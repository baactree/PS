// =====================================================================================
// 
//       Filename:  10865.cpp
//        Created:  2017년 03월 28일 23시 24분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[100001];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		cnt[a]++;
		cnt[b]++;
	}
	for(int i=1;i<=n;i++)
		printf("%d\n", cnt[i]);
	return 0;
}


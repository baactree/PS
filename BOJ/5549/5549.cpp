// =====================================================================================
// 
//       Filename:  5549.cpp
//        Created:  2017년 09월 12일 22시 14분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int q;
char mat[1005][1005];
int cnt[1005][1005][3];
char arr[3]={'J', 'O', 'I'};
int calc(int a, int b, int c, int d, int k){
	return cnt[c][d][k]-cnt[a-1][d][k]-cnt[c][b-1][k]+cnt[a-1][b-1][k];
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d", &q);
	for(int i=1;i<=n;i++)
		scanf("%s", mat[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<3;k++)
				cnt[i][j][k]=cnt[i][j-1][k]+(mat[i][j]==arr[k]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<3;k++)
				cnt[j][i][k]+=cnt[j-1][i][k];
	while(q--){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for(int i=0;i<3;i++)
			printf("%d ", calc(a, b, c, d, i));
		printf("\n");
	}
	return 0;
}


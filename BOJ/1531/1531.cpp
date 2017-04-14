// =====================================================================================
// 
//       Filename:  1531.cpp
//        Created:  2017년 04월 14일 10시 39분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[101][101];
int n, m;
void calc(int x1, int y1, int x2, int y2){
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			mat[i][j]++;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		calc(a, b, c, d);
	}
	int ans=0;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			if(mat[i][j]>m)
				ans++;
	printf("%d\n", ans);
	return 0;
}


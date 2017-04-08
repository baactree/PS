// =====================================================================================
// 
//       Filename:  10994.cpp
//        Created:  2017년 04월 07일 20시 50분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool mat[400][400];
int n;
void solve(int sx, int sy, int fx, int fy){
	if(sx==fx){
		mat[sx][sy]=true;
		return;
	}
	for(int i=sx;i<=fx;i++)
		mat[i][sy]=mat[i][fy]=true;
	for(int i=sy;i<=fy;i++)
		mat[sx][i]=mat[fx][i]=true;
	solve(sx+2, sy+2, fx-2, fy-2);
}
int main(){
	scanf("%d", &n);
	solve(0, 0, n*4-4, n*4-4);
	for(int i=0;i<n*4-3;i++){
		for(int j=0;j<n*4-3;j++)
			printf("%c", mat[i][j]?'*':' ');
		printf("\n");
	}

	return 0;
}


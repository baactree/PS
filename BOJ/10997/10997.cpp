// =====================================================================================
// 
//       Filename:  10997.cpp
//        Created:  2017년 05월 22일 19시 09분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
bool mat[500][500];
void solve(int x, int y, int k){
	int h=(k-1)*4+3;
	int w=(k-1)*4+1;
	for(int i=0;i<w;i++)
		mat[x][y-i]=true;
	for(int i=0;i<h;i++)
		mat[x+i][y-(w-1)]=true;
	for(int i=0;i<w;i++)
		mat[x+h-1][y-i]=true;
	for(int i=2;i<h;i++)
		mat[x+i][y]=true;
	mat[x+2][y-1]=true;
	if(k==2){
		for(int i=0;i<3;i++)
			mat[x+2+i][y-2]=true;
		return;
	}
	solve(x+2, y-2, k-1);
}
int main(){
	scanf("%d", &n);
	if(n==1){
		printf("*\n");
		return 0;
	}
	solve(0, (n-1)*4, n);
	for(int i=0;i<(3+(n-1)*4);i++){
		if(i==1){
			printf("*\n");
			continue;
		}
		for(int j=0;j<(n-1)*4+1;j++)
			printf("%c", mat[i][j]?'*':' ');
		printf("\n");
	}
	return 0;
}


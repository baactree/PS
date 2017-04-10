// =====================================================================================
// 
//       Filename:  1022.cpp
//        Created:  2017년 04월 10일 11시 01분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r1, c1, r2, c2;
int mat[50][5];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};
bool safe(int x, int y){
	return r1<=x&&x<=r2&&c1<=y&&y<=c2;
}
int main(){
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	int cnt=(r2-r1+1)*(c2-c1+1);
	int x, y, val;
	x=y=0;
	val=1;
	int k, dir;
	dir=3;
	k=1;
	int t=2;
	int max_len=0;
	while(cnt){
		if(k==0){
			t++;
			k=t/2;
			dir=(dir+1)%4;
			continue;
		}
		if(safe(x, y)){
			cnt--;
			mat[x-r1][y-c1]=val;
			max_len=max(max_len, (int)to_string(val).size());
		}
		k--;
		x=dx[dir]+x;
		y=dy[dir]+y;
		val++;
		
	}
	for(int i=0;i<r2-r1+1;i++){
		for(int j=0;j<c2-c1+1;j++){
			int t=to_string(mat[i][j]).size();
			for(int k=0;k<max_len-t;k++)
				printf(" ");
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}


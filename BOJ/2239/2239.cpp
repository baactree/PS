// =====================================================================================
// 
//       Filename:  2239.cpp
//        Created:  2017년 04월 01일 19시 49분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char mat[9][10];
int row[9];
int col[9];
int box[9];
void solve(int idx){
	if(idx==81){
		for(int i=0;i<9;i++)
			printf("%s\n", mat[i]);
		exit(0);
		return;
	}
	int x=idx/9;
	int y=idx%9;
	if(mat[x][y]!='0'){
		solve(idx+1);
		return;
	}
	for(int i=1;i<=9;i++){
		if(!(row[x]&(1<<i))&&!(col[y]&(1<<i))&&!(box[(x/3)*3+(y/3)]&(1<<i))){
			row[x]|=(1<<i);
			col[y]|=(1<<i);
			box[(x/3)*3+y/3]|=(1<<i);
			mat[x][y]='0'+i;
			solve(idx+1);
			mat[x][y]='0';
			box[(x/3)*3+y/3]&=~(1<<i);
			col[y]&=~(1<<i);
			row[x]&=~(1<<i);
		}
	}
}
int main(){
	for(int i=0;i<9;i++)
		scanf("%s", mat[i]);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++){
			row[i]|=(1<<(mat[i][j]-'0'));
			col[j]|=(1<<(mat[i][j]-'0'));
			box[(i/3)*3+(j/3)]|=(1<<(mat[i][j]-'0'));
		}
	solve(0);
	return 0;
}


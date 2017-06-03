// =====================================================================================
// 
//       Filename:  1347.cpp
//        Created:  2017년 06월 03일 23시 02분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int mat[1000][1000];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, -1, 0, 1};
int main(){
	cin>>n>>str;
	int x, y, dir;
	int min_x, min_y, max_x, max_y;
	min_x=min_y=max_x=max_y=x=y=500;
	mat[x][y]=1;
	dir=2;
	for(int i=0;i<str.size();i++){
		if(str[i]=='R'){
			dir=(dir+3)%4;
		}
		else if(str[i]=='L'){
			dir=(dir+1)%4;
		}
		else{
			x=x+dx[dir];
			y=y+dy[dir];
		}
		mat[x][y]=1;
		min_x=min(min_x, x);
		max_x=max(max_x, x);
		min_y=min(min_y, y);
		max_y=max(max_y, y);
	}
	for(int i=min_x;i<=max_x;i++){
		for(int j=min_y;j<=max_y;j++)
			printf("%c", mat[i][j]?'.':'#');
		printf("\n");
	}

	return 0;
}


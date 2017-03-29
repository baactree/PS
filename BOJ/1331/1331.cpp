// =====================================================================================
// 
//       Filename:  1331.cpp
//        Created:  2017년 03월 29일 00시 03분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[6][6];
char trans[300];
int dx[8]={-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8]={-2, -1, 1, 2, 2, 1, -1, -2};
bool possi(int x, int y, int x2, int y2){
	for(int i=0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx==x2&&ny==y2)
			return true;
	}
	return false;
}
int main(){
	for(int i=0;i<6;i++)
		trans[i+'A']=i;
	int nx, ny;
	string in;
	cin>>in;
	nx=trans[in[0]];
	ny=in[1]-'0'-1;
	mat[nx][ny]=true;
	int x, y;
	int sx, sy;
	sx=nx;
	sy=ny;
	bool flag=false;
	for(int i=1;i<36;i++){
		cin>>in;
		x=trans[in[0]];
		y=in[1]-'0'-1;
		if(mat[x][y])
			flag=true;
		mat[x][y]=true;
		if(!possi(x, y, nx, ny))
			flag=true;
		nx=x;
		ny=y;
	}
	if(!possi(x, y, sx, sy))
		flag=true;
	printf("%s\n", flag?"Invalid":"Valid");
	return 0;
}


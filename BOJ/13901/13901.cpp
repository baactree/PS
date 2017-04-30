// =====================================================================================
// 
//       Filename:  13901.cpp
//        Created:  2017년 04월 30일 21시 33분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, c;
int k;
bool trip[1000][1000];
int arr[4];
int dx[5]={0, -1, 1, 0, 0};
int dy[5]={0, 0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<r&&y>=0&&y<c;
}
int main(){
	scanf("%d%d", &r, &c);
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		trip[x][y]=true;
	}
	int x, y, dir;
	scanf("%d%d", &x, &y);
	for(int i=0;i<4;i++)
		scanf("%d", &arr[i]);
	dir=0;
	while(true){
		trip[x][y]=true;
		bool flag=false;
		for(int i=1;i<5;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx, ny)&&!trip[nx][ny])
				flag=true;
		}
		if(!flag)
			break;
		int nx=x+dx[arr[dir]];
		int ny=y+dy[arr[dir]];
		if(safe(nx, ny)&&!trip[nx][ny]){
			x=nx;
			y=ny;
		}
		else
			dir=(dir+1)%4;
	}
	printf("%d %d\n", x, y);
	return 0;
}


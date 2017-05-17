// =====================================================================================
// 
//       Filename:  2174.cpp
//        Created:  2017년 05월 16일 18시 55분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, c;
int n, m;
char d[255];
struct Robot{
	int x, y, dir;
};
Robot robot[101];
int mat[105][105];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
bool safe(int x, int y){
	return x>0&&x<=c&&y>0&&y<=r;
}
int main(){
	d['E']=0;
	d['N']=1;
	d['W']=2;
	d['S']=3;
	scanf("%d%d", &c, &r);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		int x, y;
		char dir[5];
		scanf("%d%d%s", &x, &y, dir);
		robot[i]={x, y, d[dir[0]]};
		mat[x][y]=i;
	}
	for(int i=0;i<m;i++){
		int a, t;
		char order[5];
		scanf("%d%s%d", &a, order, &t);
		if(order[0]=='L'){
			while(t--){
				robot[a].dir++;
				robot[a].dir%=4;
			}
		}
		else if(order[0]=='R'){
			while(t--){
				robot[a].dir+=3;
				robot[a].dir%=4;
			}
		}
		else{
			while(t--){
				int dir=robot[a].dir;
				int nx=robot[a].x+dx[dir];
				int ny=robot[a].y+dy[dir];
				if(!safe(nx, ny)){
					printf("Robot %d crashes into the wall\n", a);
					return 0;
				}
				if(mat[nx][ny]!=0){
					printf("Robot %d crashes into robot %d\n", a, mat[nx][ny]);
					return 0;
				}
				mat[robot[a].x][robot[a].y]=0;
				mat[nx][ny]=a;
				robot[a].x=nx;
				robot[a].y=ny;
			}
		}
	}
	printf("OK\n");
	return 0;
}


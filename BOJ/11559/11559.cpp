// =====================================================================================
// 
//       Filename:  11559.cpp
//        Created:  2017년 04월 29일 12시 43분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char mat[12][7];
bool trip[12][7];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<12&&y>=0&&y<6;
}
int dfs(int x, int y, char now){
	trip[x][y]=true;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&!trip[nx][ny]&&mat[nx][ny]==now){
			ret+=dfs(nx, ny, now);
		}
	}
	return ret;
}
void del(int x, int y, char now){
	mat[x][y]='.';
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&mat[nx][ny]==now)
			del(nx, ny, now);
	}
}
bool pop(){
	memset(trip, 0, sizeof(trip));
	bool ret=false;
	for(int i=0;i<12;i++)
		for(int j=0;j<6;j++){
			if(mat[i][j]!='.'&&!trip[i][j]&&dfs(i, j, mat[i][j])>=4){
				ret=true;
				del(i, j, mat[i][j]);
			}
		}
	return ret;
}
void down(){
	for(int j=0;j<6;j++){
		vector<char> temp;
		for(int i=11;i>=0;i--){
			if(mat[i][j]!='.')
				temp.push_back(mat[i][j]);
		}
		int sz=temp.size();
		for(int i=sz;i<12;i++)
			temp.push_back('.');
		for(int i=11;i>=0;i--)
			mat[i][j]=temp[11-i];
	}
}
int main(){
	for(int i=0;i<12;i++)
		scanf("%s", mat[i]);
	int ans=0;
	while(true){
		if(!pop())
			break;
		down();
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}


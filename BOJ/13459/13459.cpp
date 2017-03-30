// =====================================================================================
// 
//       Filename:  13459.cpp
//        Created:  2017년 03월 30일 00시 47분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int d, rx, ry, bx, by;
};
char mat[10][11];
int n, m;
int fx, fy;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	int srx, sry, sbx, sby;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]=='R')
				srx=i, sry=j;
			else if(mat[i][j]=='B')
				sbx=i, sby=j;
			else if(mat[i][j]=='O')
				fx=i, fy=j;
	queue<Node> q;
	q.push({0, srx, sry, sbx, sby});
	int ans=-1;
	while(!q.empty()){
		int cnt=q.front().d;
		int rx=q.front().rx;
		int ry=q.front().ry;
		int bx=q.front().bx;
		int by=q.front().by;
		q.pop();
		if(cnt==10)
			break;
		for(int i=0;i<4;i++){
			//빨간 공이 굴러가는 경우에서
			int rex=0;
			int blue=0;
			int nrx, nry;
			int rmove=0;
			nrx=rx+dx[i];
			nry=ry+dy[i];
			while(mat[nrx][nry]!='#'){
				rmove++;
				//가는 길에 B가 있는 경우
				if(nrx==bx&&nry==by)
					blue=rmove;
				//가는 길에 구멍이 있는 경우
				if(mat[nrx][nry]=='O')
					rex=rmove;
				nrx+=dx[i];
				nry+=dy[i];
			}
			bool bex=false;
			bool red=false;
			int nbx, nby;
			int bmove=0;
			nbx=bx+dx[i];
			nby=by+dy[i];
			while(mat[nbx][nby]!='#'){
				bmove++;
				//가는 길에 R이 있는 경우
				if(nbx==rx&&nby==ry)
					red=true;
				//가는 길에 구멍이 있는 경우
				if(mat[nbx][nby]=='O')
					bex=true;
				nbx+=dx[i];
				nby+=dy[i];
			}
			//서로 같은 직선상에 없는 경우
			if(!blue&&!red){
			
				if(rex){
					ans=cnt+1;
					goto print;
				}
				else if(bex){
					continue;
				}
				else{
					q.push({cnt+1, rx+dx[i]*rmove, ry+dy[i]*rmove, bx+dx[i]*bmove, by+dy[i]*bmove});
				}
			}
			//R이 가는 길에 B가 있는 경우
			else if(blue){
				//구멍이 B보다 앞쪽에 있는 경우 하나 빼야댐
				if(rex){
					if(rex<blue){
						ans=cnt+1;
						goto print;
					}
					continue;
				}
				else{
					rmove--;
					q.push({cnt+1, rx+dx[i]*rmove, ry+dy[i]*rmove, bx+dx[i]*bmove, by+dy[i]*bmove});
				}
			}
			//B가 가는 길에 R이 있는 경우
			else{
				if(rex){
					continue;
				}
				else{
					bmove--;
					q.push({cnt+1, rx+dx[i]*rmove, ry+dy[i]*rmove, bx+dx[i]*bmove, by+dy[i]*bmove});
				}
			}
		}
	}
print:
	printf("%d\n", ans==-1?0:1);
	return 0;
}

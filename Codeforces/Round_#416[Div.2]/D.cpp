// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 05월 27일 19시 04분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[105][105];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool trip[105][105];
bool safe(int x, int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
pair<int, int>  par[105][105];
queue<pair<int, int> > q;
vector<int> ans;
int dir[105][105];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%s", &mat[i][1]);
	int nx, ny;
	nx=ny=1;
	if(n==1&&m==1){
		return 0;
	}
	if(n==1){
		printf("R\n");
		fflush(stdout);
		int x, y;
		scanf("%d%d", &x, &y);
		if(y==ny){
			while(true){
				printf("L\n");
				fflush(stdout);
				scanf("%d%d", &x, &y);
				if(mat[x][y]=='F')
					return 0;
			}
		
		}
		else{
			while(true){
				printf("R\n");
				fflush(stdout);
				scanf("%d%d", &x, &y);
				if(mat[x][y]=='F')
					return 0;
			}
		}
	}
	else if(m==1){
		printf("D\n");
		fflush(stdout);
		int x, y;
		scanf("%d%d", &x, &y);
		if(x==nx){
			while(true){
				printf("U\n");
				fflush(stdout);
				scanf("%d%d", &x, &y);
				if(mat[x][y]=='F')
					return 0;
			}
		}
		else{
			while(true){
				printf("D\n");
				fflush(stdout);
				scanf("%d%d", &x, &y);
				if(mat[x][y]=='F')
					return 0;
			}
		}
	}
	else{
		bool lr=false;
		bool ud=false;
		int x, y;
		if(mat[nx][ny+1]!='*'){
			printf("R\n");
			fflush(stdout);
			scanf("%d%d", &x, &y);
			if(mat[x][y]=='F')
				return 0;
			if(ny==y){
				lr=true;
			}
			else{
				printf("L\n");
				fflush(stdout);
				scanf("%d%d", &x, &y);
			}
			int k=0;
			for(int i=0;i<m;i++){
				if(mat[nx+1][ny]!='*'){
					printf("D\n");
					fflush(stdout);
					scanf("%d%d", &x, &y);
					if(mat[x][y]=='F')
						return 0;
					if(nx==x){
						ud=true;
					}
					else{
						printf("U\n");
						fflush(stdout);
						scanf("%d%d", &x, &y);
					}
					break;
				}
				if(lr){
					printf("L\n");
					fflush(stdout);
					scanf("%d%d", &nx, &ny);
					if(mat[nx][ny]=='F')
						return 0;
				}
				else{
					printf("R\n");
					fflush(stdout);
					scanf("%d%d", &nx, &ny);
					if(mat[nx][ny]=='F')
						return 0;
				}
			}
		}
		else if(mat[nx+1][ny]!='*'){
			printf("D\n");
			fflush(stdout);
			scanf("%d%d", &x, &y);
			if(mat[x][y]=='F')
				return 0;
			if(nx==x){
				ud=true;
			}
			else{
				printf("U\n");
				fflush(stdout);
				scanf("%d%d", &x, &y);
			}
			for(int i=0;i<n;i++){
				if(mat[nx][ny+1]!='*'){
					printf("R\n");
					fflush(stdout);
					scanf("%d%d", &x, &y);
					if(mat[x][y]=='F')
						return 0;
					if(ny==y){
						lr=true;
					}
					else{
						printf("L\n");
						fflush(stdout);
						scanf("%d%d", &x, &y);
					}
					break;
				}
				if(ud){
					printf("U\n");
					fflush(stdout);
					scanf("%d%d", &nx, &ny);
					if(mat[nx][ny]=='F')
						return 0;
				}
				else{
					printf("D\n");
					fflush(stdout);
					scanf("%d%d", &nx, &ny);
					if(mat[nx][ny]=='F')
						return 0;
				}
			}
		}
		trip[nx][ny]=true;
		q.push({nx, ny});
		par[nx][ny]={nx, ny};
		while(!q.empty()){
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			if(mat[x][y]=='F')
				break;
			for(int i=0;i<4;i++){
				int tx=x+dx[i];
				int ty=y+dy[i];
				if(safe(tx, ty)&&mat[tx][ty]!='*'&&!trip[tx][ty]){
					trip[tx][ty]=true;
					par[tx][ty]={x, y};
					dir[tx][ty]=i;
					q.push({tx, ty});
				}
			}
		}
		pair<int, int> now={0, 0};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(mat[i][j]=='F')
					now={i, j};
			}
		while(now.first!=nx||now.second!=ny){
			ans.push_back(dir[now.first][now.second]);
			now=par[now.first][now.second];
		}
		reverse(ans.begin(), ans.end());
		for(int i=0;i<ans.size();i++){
			if(ans[i]==0){
				printf("%c\n", ud?'D':'U');
				fflush(stdout);
				scanf("%d%d", &x, &y);
			}
			else if(ans[i]==1){
				printf("%c\n", ud?'U':'D');
				fflush(stdout);
				scanf("%d%d", &x, &y);
			}
			else if(ans[i]==2){
				printf("%c\n", lr?'R':'L');
				fflush(stdout);
				scanf("%d%d", &x, &y);
			}
			else{
				printf("%c\n", lr?'L':'R');
				fflush(stdout);
				scanf("%d%d", &x, &y);
			}
		}
	}
	return 0;
}


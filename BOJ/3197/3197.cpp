// =====================================================================================
// 
//       Filename:  3197.cpp
//        Created:  2017년 08월 28일 23시 14분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[2000][2000];
int col[2000][2000];
int par[4000000];
int melt[2000][2000];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
vector<pair<int, int> > tt;
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	par[x]=y;
}
void dfs(int x, int y, int cnt){
	col[x][y]=cnt;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)){
			if(mat[nx][ny]=='X'&&melt[nx][ny]==-1){
				melt[nx][ny]=1;
				tt.push_back({nx, ny});
			}
			if(mat[nx][ny]=='.'&&col[nx][ny]==-1){
				dfs(nx, ny, cnt);
			}
			if(mat[nx][ny]=='.'&&col[nx][ny]!=-1){
				merge(col[nx][ny], col[x][y]);
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	for(int i=0;i<4000000;i++)
		par[i]=i;
	vector<pair<int, int> > p;
	vector<pair<int, int> > t;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(mat[i][j]=='L'){
				p.push_back({i, j});
				mat[i][j]='.';
			}
			if(mat[i][j]!='X')
				t.push_back({i, j});
		}
	memset(col, -1, sizeof(col));
	memset(melt, -1, sizeof(melt));
	int ans=0;
	int cnt=0;
	while(true){
		tt.clear();
		for(int i=0;i<t.size();i++){
			int x=t[i].first;
			int y=t[i].second;
			if(col[x][y]==-1){
				dfs(x, y, cnt);
				cnt++;
			}
		}
		if(find(col[p[0].first][p[0].second])==find(col[p[1].first][p[1].second]))
			return !printf("%d\n", ans);
		t=tt;
		for(int i=0;i<t.size();i++){
			int x=t[i].first;
			int y=t[i].second;
			mat[x][y]='.';
		}
		ans++;
	}
	return 0;
}


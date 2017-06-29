// =====================================================================================
// 
//       Filename:  11014.cpp
//        Created:  2017년 06월 29일 11시 38분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[100][100];
int dx[6]={-1, -1, 0, 1, 1, 0};
int dy[6]={-1, 1, 1, 1, -1, -1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
vector<int> adj[6400];
int matched[6400];
int level[6400];
bool used[6400];
int idx[6400];
void bfs(){
	queue<int> q;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j+=2){
			if(!used[i*m+j]){
				q.push(i*m+j);
				level[i*m+j]=0;
			}
			else
				level[i*m+j]=-1;
		}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			if(matched[there]!=-1&&level[matched[there]]==-1){
				level[matched[there]]=level[now]+1;
				q.push(matched[there]);
			}
		}
	}
}
bool dfs(int now){
	for(int &i=idx[now];i<adj[now].size();i++){
		int there=adj[now][i];
		if(matched[there]==-1||(level[matched[there]]==level[now]+1&&dfs(matched[there]))){
			matched[there]=now;
			used[now]=true;
			return true;
		}
	}
	return false;
}
bool dfs2(int now){
	if(used[now])
		return false;
	used[now]=true;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(matched[there]==-1||dfs2(matched[there])){
			matched[there]=now;
			return true;
		}
	}
	return false;
}
#define HK
//#define BM
int max_flow(){
	int ret=0;
	memset(matched, -1, sizeof(matched));
#ifdef HK 
	memset(used, 0, sizeof(used));
	while(true){
		bfs();
		int f=0;
		memset(idx, 0, sizeof(idx));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j+=2){
				if(!used[i*m+j]&&dfs(i*m+j)){
					f++;
				}
			}
		if(f==0)
			break;
		ret+=f;
	}
#endif
#ifdef BM
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j+=2){
			memset(used, 0, sizeof(used));
			if(dfs2(i*m+j))
				ret++;
	}
#endif
	return ret;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;i++)
			scanf("%s", &mat[i]);
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(mat[i][j]=='.')
					cnt++;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j+=2){
				adj[i*m+j].clear();
				if(mat[i][j]=='x')
					continue;
				for(int k=0;k<6;k++){
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(safe(nx, ny)&&mat[nx][ny]=='.'){
						adj[i*m+j].push_back(nx*m+ny);
					}
				}
			}
		int k=max_flow();
		printf("%d\n", cnt-k);
	}
	return 0;
}


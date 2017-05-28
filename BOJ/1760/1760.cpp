// =====================================================================================
// 
//       Filename:  1760.cpp
//        Created:  2017년 05월 28일 20시 05분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int r[100][100];
int c[100][100];
int mat[100][100];
int ridx, cidx;
vector<int> adj[20000];
int matched[20000];
bool used[20000];
int level[20000];
void bfs(){
	memset(level, -1, sizeof(level));
	queue<int> q;
	for(int i=0;i<ridx;i++)
		if(!used[i]){
			q.push(i);
			level[i]=0;
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
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(matched[there]==-1||(level[matched[there]]==level[now]+1&&dfs(matched[there]))){
			matched[there]=now;
			used[now]=true;
			return true;
		}
	}
	return false;
}
int flow(){
	int ret=0;
	memset(matched, -1, sizeof(matched));
	while(true){
		bfs();
		int f=0;
		for(int i=0;i<ridx;i++)
			if(!used[i]&&dfs(i))
				f++;
		if(f==0)
			break;
		ret+=f;
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(mat[i][j]==2)
				continue;
			if(j==0||mat[i][j-1]==2)
				r[i][j]=ridx++;
			else
				r[i][j]=r[i][j-1];
		}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			if(mat[j][i]==2)
				continue;
			if(j==0||mat[j-1][i]==2)
				c[j][i]=cidx++;
			else
				c[j][i]=c[j-1][i];
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]==0)
				adj[r[i][j]].push_back(c[i][j]);
	printf("%d\n", flow());
	return 0;
}


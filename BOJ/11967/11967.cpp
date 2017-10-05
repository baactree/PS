#include <bits/stdc++.h>
using namespace std;
int n,m;
bool p1[105][105],p2[105][105];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x,int y){
	return min(x,y)>0&&max(x,y)<=n;
}
vector<pair<int,int> > adj[105][105];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		adj[a][b].push_back({c,d});
	}
	queue<pair<int,int> > q;
	int cnt=1;
	p1[1][1]=true;
	p2[1][1]=true;
	q.push({1,1});
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<adj[x][y].size();i++){
			int nx=adj[x][y][i].first;
			int ny=adj[x][y][i].second;
			if(!p2[nx][ny]){
				p2[nx][ny]=true;
				cnt++;
				if(p1[nx][ny]){
					q.push({nx,ny});
				}
			}
		}
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx,ny)&&!p1[nx][ny]){
				p1[nx][ny]=true;
				if(p2[nx][ny])
					q.push({nx,ny});
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
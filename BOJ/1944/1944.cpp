#include <bits/stdc++.h>
using namespace std;
int n,m;
char mat[55][55];
bool trip[55][55];
int dist[55][55];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x,int y){
	return min(x,y)>=0&&max(x,y)<n;
}
void push(int x,int y,priority_queue<pair<int,pair<int,int> > > &pq){
	memset(dist,-1,sizeof(dist));
	queue<pair<int,int> > q;
	q.push({x,y});
	dist[x][y]=0;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(mat[x][y]=='K')
			pq.push({-dist[x][y],{x,y}});
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx,ny)&&!trip[nx][ny]&&mat[nx][ny]!='1'&&dist[nx][ny]==-1){
				dist[nx][ny]=dist[x][y]+1;
				q.push({nx,ny});
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mat[i]);
	int sx,sy;
	sx=sy=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mat[i][j]=='S'){
				sx=i;
				sy=j;
			}
	int ans=0;
	int cnt=0;
	priority_queue<pair<int,pair<int,int> > > pq;
	pq.push({0,{sx,sy}});
	while(!pq.empty()){
		int cost=-pq.top().first;
		int x=pq.top().second.first;
		int y=pq.top().second.second;
		pq.pop();
		if(trip[x][y])
			continue;
		ans+=cost;
		trip[x][y]=true;
		push(x,y,pq);
		cnt++;
	}
	if(cnt!=m+1)
		return !printf("-1\n");
	printf("%d\n",ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m;
int mat[55][55];
bool trip[55][55];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
bool possi(int sx,int sy,int h){
	memset(trip,0,sizeof(trip));
	queue<pair<int,int> > q;
	q.push({sx,sy});
	trip[sx][sy]=true;
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(!safe(nx,ny))
				return false;
			if(mat[nx][ny]<h&&!trip[nx][ny]){
				trip[nx][ny]=true;
				q.push({nx,ny});
			}
		}
	}
	return true;
}
int bfs(int sx,int sy){
	int le,ri,mid,ans;
	le=mat[sx][sy];
	ri=9;
	ans=le;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(sx,sy,mid)){
			ans=mid;
			le=mid+1;
		}
		else
			ri=mid-1;
	}
	return ans-mat[sx][sy];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d",&mat[i][j]);
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			ans+=bfs(i,j);
		}
	printf("%d\n",ans);
	return 0;
}
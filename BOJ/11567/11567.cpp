#include <bits/stdc++.h>
using namespace std;
char mat[505][505];
bool trip[505][505];
int n,m;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
bool possi(int x,int y,int k){
	int cnt=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx,ny)&&mat[nx][ny]=='.')
			cnt++;
	}
	return cnt>=k;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mat[i]);
	int sx,sy,fx,fy;
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	sx--;sy--;
	fx--;fy--;
	queue<pair<int,int> >q;
	q.push({sx,sy});
	trip[sx][sy]=true;
	int cnt=0;
	mat[sx][sy]='.';
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(x==fx&&y==fy){
			if(mat[x][y]=='X'||possi(x,y,cnt+1))
				return !printf("YES\n");
			return !printf("NO\n");			
		}
		if(mat[x][y]=='X')
			continue;
		if(!cnt)
			cnt=1;
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx,ny)&&!trip[nx][ny]){
				trip[nx][ny]=true;
				q.push({nx,ny});
			}
		}
	}
	printf("NO\n");
	return 0;
}
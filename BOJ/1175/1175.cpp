#include <bits/stdc++.h>
using namespace std;
//s->a->b
//s->b->a
int dist[3][4][55][55][4];
int n,m;
char mat[55][55];
vector<pair<int,int> > st;
const int inf=0x3f3f3f3f;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x,int y){
	return min(x,y)>=0&&x<n&&y<m;
}
void solve(int idx,int sdir){
	int sx=st[idx].first;
	int sy=st[idx].second;
	queue<pair<pair<int,int>,int> > q;
	q.push({{sx,sy},sdir});
	dist[idx][sdir][sx][sy][sdir]=0;
	while(!q.empty()){
		int x=q.front().first.first;
		int y=q.front().first.second;
		int dir=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			if(dir==i)
				continue;
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(safe(nx,ny)&&mat[nx][ny]!='#'&&dist[idx][sdir][nx][ny][i]==inf){
				dist[idx][sdir][nx][ny][i]=dist[idx][sdir][x][y][dir]+1;
				q.push({{nx,ny},i});
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mat[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]=='S')
				st.push_back({i,j});
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mat[i][j]=='C')
				st.push_back({i,j});
	memset(dist,0x3f,sizeof(dist));
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
			solve(i,j);
	int ans=inf;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++){
				ans=min(ans,dist[0][i][st[1].first][st[1].second][j]+
					dist[1][j][st[2].first][st[2].second][k]);
				ans=min(ans,dist[0][i][st[2].first][st[2].second][j]+
					dist[2][j][st[1].first][st[1].second][k]);
			}
	printf("%d\n",ans==inf?-1:ans);
	return 0;
}
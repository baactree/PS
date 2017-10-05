#include <bits/stdc++.h>
using namespace std;
char mat[5][5];
bool trip[5][5];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x,int y){
	return min(x,y)>=0&&max(x,y)<3;
}
int n,m;
vector<pair<int,int> > ans;
bool possi(){
	int now=mat[ans[0].first][ans[0].second]-'0';
	for(int i=1;i<m*2-1;i+=2){
		if(mat[ans[i].first][ans[i].second]=='+')
			now+=mat[ans[i+1].first][ans[i+1].second]-'0';
		else
			now-=mat[ans[i+1].first][ans[i+1].second]-'0';	
	}
	return now==n;
}
void dfs(int x,int y,int cnt){
	trip[x][y]=true;
	ans.push_back({x,y});
	if(cnt==m*2-1){
		if(possi()){
			printf("1\n");
			for(int i=0;i<ans.size();i++)
				printf("%d %d\n",ans[i].first,ans[i].second);
			exit(0);
		}
	}
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx,ny)&&!trip[nx][ny])
			dfs(nx,ny,cnt+1);
	}
	ans.pop_back();
	trip[x][y]=false;
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<3;i++)
		scanf("%s",mat[i]);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if((i+j)%2==0){
				dfs(i,j,1);
			}
		}
	}
	printf("0\n");
	return 0;
}
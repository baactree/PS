#include <bits/stdc++.h>
using namespace std;
int n,m;
char mat[2000][1005];
vector<int> adj[1005];
int matched[2005];
int trip[1005];
bool check(){
	for(int i=0;i<n;i++){
		bool flag=false;
		for(int j=0;j<2*m;j++){
			if(mat[j][i]=='O')
				flag=true;
		}
		if(!flag)
			return true;
	}
	return false;
}
bool possi(int a,int b){
	bool flag1,flag2;
	flag1=flag2=false;
	for(int i=0;i<n;i++){
		int now=(mat[a][i]=='O'||mat[b][i]=='O')?1:0;
		if(now==0)
			flag1=true;
		else
			flag2=true;
	}
	return flag1&&flag2;
}
bool dfs(int now){
	if(trip[now])
		return false;
	trip[now]=true;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(matched[there]==-1||dfs(matched[there])){
			matched[there]=now;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m*2;i++)
		scanf("%s",mat[i]);
	if(check())
		return !printf("No\n");
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			if(possi(i,j+m))
				adj[i].push_back(j+m);
	memset(matched,-1,sizeof(matched));
	int flow=0;
	for(int i=0;i<m;i++){
		memset(trip,0,sizeof(trip));
		if(dfs(i))
			flow++;
	}
	if(flow!=m)
		return !printf("No\n");
	printf("Yes\n");
	for(int i=0;i<m;i++)
		printf("%d %d\n",matched[i+m]+1,i+1);
	return 0;
}
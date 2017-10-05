#include <bits/stdc++.h>
using namespace std;
int n,m;
int cache[16][1<<16];
int mat[4][4];
int solve(int idx,int state){
	if(idx==n*m)
		return 0;
	int &ret=cache[idx][state];
	if(ret!=-1)
		return ret;
	if(state&(1<<idx))
		return ret=solve(idx+1,state);
	int next=state;
	int x=idx/m;
	int y=idx%m;
	int sum=0;
	while(y<m&&!(state&(1<<(x*m+y)))){
		sum=sum*10+mat[x][y];
		next|=(1<<(x*m+y));
		ret=max(ret,solve(idx+1,next)+sum);
		y++;
	}
	next=state;
	x=idx/m;
	y=idx%m;
	sum=0;
	while(x<n&&!(state&(1<<(x*m+y)))){
		sum=sum*10+mat[x][y];
		next|=(1<<(x*m+y));
		ret=max(ret,solve(idx+1,next)+sum);
		x++;
	}
	return ret;
}
int main(){
	memset(cache,-1,sizeof(cache));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d",&mat[i][j]);
	printf("%d\n",solve(0,0));
	return 0;
}
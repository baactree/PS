#include <bits/stdc++.h>
using namespace std;
int n,m;
char mat[405][405];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char p[4];
bool safe(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
bool possi(int x,int y){
	int ret=0;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(safe(nx,ny)&&mat[nx][ny]==p[i])
			ret|=(1<<i);
	}
	if((ret&3)==3||(ret&12)==12)
		return true;
	return false;
}
int main(){
	p[0]=118;
	p[1]=94;
	p[2]=62;
	p[3]=60;
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",mat[i]);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(mat[i][j]==111&&possi(i,j))
					ans++;
				printf("%d\n",ans);
	}
	return 0;
}
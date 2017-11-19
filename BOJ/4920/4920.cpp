#include <bits/stdc++.h>
using namespace std;
int n;
int mat[205][205];
int p[5][4][4]={
	{
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
		{0,0,0,0}
	},
	{
		{1,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
		{0,0,0,0},
	},
	{
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}
};
bool safe(int x,int y){
	return x>=50&&x<n+50&&y>=50&&y<n+50;
}
int main(){
	int tc=1;
	while(true){
		scanf("%d",&n);
		if(!n)
			break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&mat[i+50][j+50]);
		int ans=-1e9;
		for(int t=0;t<5;t++){
			for(int k=0;k<4;k++){
				for(int i=47;i<n+50;i++)
					for(int j=47;j<n+50;j++){
						int now=0;
						bool flag=false;
						for(int x=0;x<4;x++)
							for(int y=0;y<4;y++){
								if(p[t][x][y]){
									if(!safe(x+i,y+j))
										flag=true;
									now+=mat[x+i][y+j];
								}
							}
						if(!flag){
							ans=max(ans,now);
						}
					}
				int temp[4][4]={0,};
				for(int x=0;x<4;x++)
					for(int y=0;y<4;y++)
						temp[y][3-x]=p[t][x][y];
				for(int x=0;x<4;x++)
					for(int y=0;y<4;y++)
						p[t][x][y]=temp[x][y];
			}
		}
		printf("%d. %d\n",tc++,ans);
	}
	return 0;
}
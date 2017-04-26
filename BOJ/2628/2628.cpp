#include <iostream>
#include <stdio.h>
using namespace std;
int m,n;
int mat[105][105];
int cutr[105];
int cutc[105];
bool trip[105][105];
int dx[2]={1,0};
int dy[2]={0,1};
bool safe(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
int dfs(int x,int y){
    int ret=1;
    trip[x][y]=true;
    for(int i=0;i<2;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(safe(nx,ny)&&!trip[nx][ny]){
            if(i==0){
                if(!cutr[nx])
                    ret+=dfs(nx,ny);
            }
            else{
                if(!cutc[ny])
                    ret+=dfs(nx,ny);
            }
        }
    }
    return ret;
}
int main(){
    scanf("%d%d",&m,&n);
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a){
            cutc[b]=1;
        }
        else{
            cutr[b]=1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!trip[i][j]){
                int temp=dfs(i,j);
                ans=max(ans,temp);
            }
        }
    printf("%d\n",ans);
    return 0;
}
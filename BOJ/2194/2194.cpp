#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,k;
int mat[500][500];
int dist[500][500];
int sx,sy,fx,fy;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x,int y){
    return x>=0&&x+a<=n&&y>=0&&y+b<=m;
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        mat[x-1][y-1]=1;
    }
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    sx--;sy--;fx--;fy--;
    memset(dist,-1,sizeof(dist));
    dist[sx][sy]=0;
    queue<pair<int,int> > q;
    q.push({sx,sy});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(safe(nx,ny)&&dist[nx][ny]==-1){
                int cnt=0;
                for(int j=0;j<a;j++)
                    for(int k=0;k<b;k++)
                        cnt+=mat[nx+j][ny+k];
                if(cnt==0){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    printf("%d\n",dist[fx][fy]);
    return 0;
}
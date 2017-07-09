#include <bits/stdc++.h>
using namespace std;
int r,c;
char mat[30][30];
char trans[10]={'.','|','-','+','1','2','3','4','M','Z'};
int sx,sy,fx,fy;
bool trip[30][30];
//해당 방향에 반드시 있어야 하는 것들
bool adj[10][4]={
    {0,0,0,0},
    {1,0,0,1},
    {0,1,1,0},
    {1,1,1,1},
    {0,0,1,1},
    {1,0,1,0},
    {1,1,0,0},
    {0,1,0,1},
    {1,1,1,1},
    {1,1,1,1}
};
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
bool safe(int x,int y){
    return x>=0&&x<r&&y>=0&&y<c;
}
void dfs(int x,int y){
    if(trip[x][y])
        return;
    trip[x][y]=true;
    if(mat[x][y]==9)
        return;
    int k=mat[x][y];
    for(int i=0;i<4;i++){
        if(!adj[k][i])
            continue;
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(safe(nx,ny)){
            int nk=mat[nx][ny];
            if(k==8&&nk==9)
                continue;
            if(adj[nk][3-i]){
                dfs(nx,ny);
            }
        }
    }
}
bool possi(int x,int y){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(mat[i][j]>0&&mat[i][j]<8){
                int k = mat[i][j];
                for (int q = 0; q < 4; q++){
                    if (!adj[k][q])
                        continue;
                    int nx = i + dx[q];
                    int ny = j + dy[q];
                    if (!safe(nx, ny))
                        return false;
                    int nk = mat[nx][ny];
                    if (!adj[nk][3 - q])
                        return false;
                }
            }
        }
    
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=sx+dx[i];
        int ny=sy+dy[i];
        if(safe(nx,ny)&&mat[nx][ny]>0&&mat[nx][ny]<8)
            cnt++;
    }
    if(cnt!=1)
        return false;
    cnt=0;
    for(int i=0;i<4;i++){
        int nx=fx+dx[i];
        int ny=fy+dy[i];
        if(safe(nx,ny)&&mat[nx][ny]>0&&mat[nx][ny]<8)
            cnt++;
    }
    if(cnt!=1)
        return false;
    memset(trip,0,sizeof(trip));
    dfs(sx,sy);
    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(mat[i][j]==0&&trip[i][j])
                return false;
            if(mat[i][j]!=0&&!trip[i][j])
                return false;
        }
    return true;
}
int main(){
    
    
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++)
        scanf("%s",mat[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            for(int k=0;k<10;k++)
                if(mat[i][j]==trans[k]){
                    mat[i][j]=k;
                    if(k==9){
                        fx=i;
                        fy=j;
                    }
                    if(k==8){
                        sx=i;
                        sy=j;
                    }
                    break;
                }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(mat[i][j]==0){
                for(int k=1;k<8;k++){
                    mat[i][j]=k;
                    if(possi(i,j)){
                        printf("%d %d %c",i+1,j+1,trans[k]);
                        return 0;
                    }
                }
                mat[i][j]=0;
            }
    return 0;
}
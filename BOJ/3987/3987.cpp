#include <bits/stdc++.h>
using namespace std;
int n,m;
char mat[505][505];
int sx,sy;
bool trip[505][505][4];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int k[4]={0,2,3,1};
bool safe(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
bool flag;
char trans[4]={'U','D','L','R'};
int dfs(int x,int y,int d){
    if(trip[x][y][d]){
        flag=true;
        return 0;
    }
    if(!safe(x,y)||mat[x][y]=='C')
        return 0;
    trip[x][y][d]=true;
    int ret=1;
    if(mat[x][y]=='/'){
        int nd=3-d;
        int nx=x+dx[nd];
        int ny=y+dy[nd];
        return ret+dfs(nx,ny,nd);
    }
    if(mat[x][y]=='\\'){
        int nd=(d+2)%4;
        int nx=x+dx[nd];
        int ny=y+dy[nd];
        return ret+dfs(nx,ny,nd);
    }
    int nx=x+dx[d];
    int ny=y+dy[d];
    return ret+dfs(nx,ny,d);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mat[i]);
    scanf("%d%d",&sx,&sy);
    sx--;sy--;
    int ans=0;
    int dir=-1;
    for(int i=0;i<4;i++){
        memset(trip,0,sizeof(trip));
        flag=false;
        int temp=dfs(sx,sy,i);
        if(flag)
            temp=0x3f3f3f3f;
        if(ans<temp){
            ans=temp;
            dir=i;
        }
        else if(temp==ans){
            if(k[i]<k[dir]){
                dir=i;
            }
        }
    }
    printf("%c\n",trans[dir]);
    if(ans==0x3f3f3f3f)
        printf("Voyager\n");
    else
        printf("%d\n",ans);
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int n,m;
int mat[50][50];
bool trip[50][50];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool safe(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
struct Node{
    int x,y,dir;
    Node(int x,int y,int dir):x(x),y(y),dir(dir){}
};
int main(){
    scanf("%d%d",&n,&m);
    int sx,sy,sdir;
    scanf("%d%d%d",&sx,&sy,&sdir);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mat[i][j]);
    queue<Node> q;
    q.push(Node(sx,sy,sdir));
    int ans=0;
    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int dir=q.front().dir;
        q.pop();
        trip[x][y]=true;
        ans++;
        int tdir,tx,ty;
        back:
        for(int i=1;i<=4;i++){
            int ndir=(dir-i+4)%4;
            int nx=x+dx[ndir];
            int ny=y+dy[ndir];
            if(safe(nx,ny)&&!trip[nx][ny]&&mat[nx][ny]==0){
                q.push(Node(nx,ny,ndir));
                goto next;
            }
        }
        tdir=(dir+2)%4;
        tx=x+dx[tdir];
        ty=y+dy[tdir];
        if(safe(tx,ty)&&mat[tx][ty]==0){
            x=tx;
            y=ty;
            goto back;
        }
        next:
        continue;
    }
    printf("%d\n",ans);
    return 0;
}
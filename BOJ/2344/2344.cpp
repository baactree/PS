#include <bits/stdc++.h>
using namespace std;
int n,m;
int mat[1000][1000];
int ans[4005];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int trans[4]={3,2,1,0};
bool safe(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
int calc(int x,int y,int dir){
    while(true){
        if(mat[x][y]==1){
            dir=trans[dir];
        }
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(!safe(nx,ny))
            break;
        x=nx;
        y=ny;
    }
    if(x==0&&dir==0){
        return 2*(n+m)-y;
    }
    if(x==n-1&&dir==1){
        return n+y+1;
    }
    if(y==0&&dir==2){
        return x+1;
    }
    return n+m+n-x;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mat[i][j]);
    for(int i=0;i<n;i++){
        int v=calc(i,0,3);
        ans[i+1]=v;
        v=calc(i,m-1,2);
        ans[n+m+n-i]=v;
    }
    for(int i=0;i<m;i++){
        int v=calc(0,i,1);
        ans[2*(n+m)-i]=v;
        v=calc(n-1,i,0);
        ans[n+i+1]=v;
    }
    for(int i=1;i<=2*(n+m);i++)
        printf("%d ",ans[i]);
    return 0;
}
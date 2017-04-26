#include <iostream>
#include <stdio.h>
using namespace std;
int r,s;
char mat[50][51];
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
bool safe(int x,int y){
    return x>=0&&x<r&&y>=0&&y<s;
}
int count(int x,int y){
    int ret=0;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(safe(nx,ny)&&mat[nx][ny]=='o')
            ret++;
    }
    return ret;
}
int main(){
    scanf("%d%d",&r,&s);
    for(int i=0;i<r;i++)
        scanf("%s",mat[i]);
    int cnt=-1;
    int sx,sy;
    sx=sy=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++){
            if(mat[i][j]=='.'){
                int temp=count(i,j);
                if(temp>cnt){
                    cnt=temp;
                    sx=i;
                    sy=j;
                }
            }
        }
    if(cnt!=-1){
        mat[sx][sy]='o';
    }
    int ans=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++)
            if(mat[i][j]=='o')
                ans+=count(i,j);
    printf("%d\n",ans/2);
    return 0;
}
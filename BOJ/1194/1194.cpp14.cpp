#include "bits/stdc++.h"
using namespace std;
char mat[50][51];
bool trip[50][50][1<<6];
int N,M;
struct Node{
    int x,y,state,cnt;
    Node(int x,int y,int state,int cnt):x(x),y(y),state(state),cnt(cnt){}
};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool safe(int x,int y){
    return x>=0&&x<N&&y>=0&&y<M;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
        scanf("%s",mat[i]);
    int sx,sy,fx,fy;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            if(mat[i][j]=='0')
                sx=i,sy=j;
            else if(mat[i][j]=='1')
                fx=i,fy=j;
        }
   queue<Node> q;
   trip[sx][sy][0]=true;
   q.push({sx,sy,0,0});
    int ans=-1;
    while(!q.empty()){
        int nx=q.front().x;
        int ny=q.front().y;
        int nstate=q.front().state;
        int ncnt=q.front().cnt;
        q.pop();
        if(mat[nx][ny]=='1'){
            ans=ncnt;
            break;
        }
        for(int i=0;i<4;i++){
            int tx=nx+dx[i];
            int ty=ny+dy[i];
            if(safe(tx,ty)){
                if(mat[tx][ty]!='#'){
                    if(mat[tx][ty]>='A'&&mat[tx][ty]<='Z'){
                        if(nstate&(1<<(mat[tx][ty]-'A'))){
                            if(!trip[tx][ty][nstate]){
                                trip[tx][ty][nstate]=true;
                                q.push({tx,ty,nstate,ncnt+1});
                            }
                        }
                    }
                    else if(mat[tx][ty]>='a'&&mat[tx][ty]<='z'){
                        int tstate=nstate|(1<<(mat[tx][ty]-'a'));
                        if(!trip[tx][ty][tstate]){
                            trip[tx][ty][tstate]=true;
                            q.push({tx,ty,tstate,ncnt+1});
                        }
                    }
                    else{
                        if(!trip[tx][ty][nstate]){
                            trip[tx][ty][nstate]=true;
                            q.push({tx,ty,nstate,ncnt+1});
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
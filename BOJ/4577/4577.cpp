#include <bits/stdc++.h>
using namespace std;
int r,c;
string order;
char mat[20][20];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char p[255];
bool safe(int x,int y){
    return x>=0&&x<r&&y>=0&&y<c;
}
int main(){
    p['U']=0;
    p['D']=1;
    p['L']=2;
    p['R']=3;
    int tc=1;
    while(scanf("%d%d",&r,&c)!=EOF){
        if(r==0&&c==0)
            break;
        for(int i=0;i<r;i++)
            scanf("%s",mat[i]);
        cin>>order;
        int x,y;
        int t=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(mat[i][j]=='w'){
                    x=i;
                    y=j;
                    mat[i][j]='.';
                }
                else if(mat[i][j]=='W'){
                    x=i;
                    y=j;
                    mat[i][j]='+';
                }
                else if(mat[i][j]=='b')
                    t++;
        for(int i=0;i<order.size();i++){
            if(t==0)
                break;
            int k=p[order[i]];
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(!safe(nx,ny)||mat[nx][ny]=='#')
                continue;
            if(mat[nx][ny]=='.'||mat[nx][ny]=='+'){
                x=nx;
                y=ny;
                continue;
            }
            if(mat[nx][ny]=='b'||mat[nx][ny]=='B'){
                int tx=nx+dx[k];
                int ty=ny+dy[k];
                if(!safe(tx,ty)||mat[tx][ty]=='#'||mat[tx][ty]=='b'||mat[tx][ty]=='B')
                    continue;
                if(mat[tx][ty]=='.'){
                    if(mat[nx][ny]=='b'){
                        mat[nx][ny]='.';
                        t--;
                    }
                    else if(mat[nx][ny]=='B')
                        mat[nx][ny]='+';
                    mat[tx][ty]='b';
                    t++;
                    x=nx;
                    y=ny;
                }
                else if(mat[tx][ty]=='+'){
                    if(mat[nx][ny]=='b'){
                        t--;
                        mat[nx][ny]='.';
                    }
                    else if(mat[nx][ny]=='B')
                        mat[nx][ny]='+';
                    mat[tx][ty]='B';
                    x=nx;
                    y=ny;
                }
            }
        }
        if(mat[x][y]=='.')
            mat[x][y]='w';
        else if(mat[x][y]=='+')
            mat[x][y]='W';
        int cnt=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(mat[i][j]=='b')
                    cnt++;
        printf("Game %d: %s\n",tc++,cnt==0?"complete":"incomplete");
        for(int i=0;i<r;i++)
            printf("%s\n",mat[i]);
    }
    return 0;
}
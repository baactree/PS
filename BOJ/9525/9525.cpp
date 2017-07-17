#include <bits/stdc++.h>
using namespace std;
int r[100][100];
int c[100][100];
vector<int> adj[10005];
bool trip[10005];
int level[10005];
int matched[10005];
int idx[10005];
int ridx,cidx;
int n;
char mat[105][105];
bool safe(int x,int y){
    return x>=0&&x<n&&y>=0&&y<n;
}
void color(int mode,int x,int y,int num){
    if(mode){
        while(true){
            c[x][y]=num;
            x=x+1;
            if(!safe(x,y)||mat[x][y]=='X')
                break;
        }
    }
    else{
        while(true){
            r[x][y]=num;
            y=y+1;
            if(!safe(x,y)||mat[x][y]=='X')
                break;
        }
    }
}
void bfs(int k){
    queue<int> q;
    for(int i=0;i<k;i++){
        if(!trip[i]){
            q.push(i);
            level[i]=0;
        }
        else
            level[i]=-1;
    }
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<adj[now].size();i++){
            int there=adj[now][i];
            if(matched[there]!=-1&&level[matched[there]]==-1){
                level[matched[there]]=level[now]+1;
                q.push(matched[there]);
            }
        }
    }
}
bool dfs(int now){
    for(int &i=idx[now];i<adj[now].size();i++){
        int there=adj[now][i];
        if(matched[there]==-1||(level[matched[there]]==level[now]+1&&dfs(matched[there]))){
            matched[there]=now;
            trip[now]=true;
            return true;
        }
    }
    return false;
}
int flow(int k){
    int ret=0;
    memset(matched,-1,sizeof(matched));
    while(true){
        bfs(k);
        memset(idx,0,sizeof(idx));
        int f=0;
        for(int i=0;i<k;i++)
            if(!trip[i]&&dfs(i))
                f++;
        ret+=f;
        if(f==0)
            break;
    }
    return ret;
}
int main(){
    memset(r,-1,sizeof(r));
    memset(c,-1,sizeof(c));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",mat[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(mat[i][j]=='X')
                continue;
            if(r[i][j]==-1)
                color(0,i,j,ridx++);
            if(c[i][j]==-1)
                color(1,i,j,cidx++);
            adj[r[i][j]].push_back(c[i][j]);
        }
    printf("%d\n",flow(ridx));
    return 0;
}
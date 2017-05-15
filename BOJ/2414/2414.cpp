#include <bits/stdc++.h>
using namespace std;
int ridx[50][50];
int cidx[50][50];
int rn,cn;
int n,m;
char mat[55][55];
vector<vector<int> >  adj;
vector<bool> trip;
vector<int> level;
vector<int> matched;
void bfs(){
    level=vector<int>(rn,-1);
    queue<int> q;
    for(int i=0;i<rn;i++)
        if(!trip[i]){
            q.push(i);
            level[i]=0;
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
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(matched[there]==-1||(level[matched[there]]==level[now]+1&&dfs(matched[there]))){
            matched[there]=now;
            trip[now]=true;
            return true;
        }
    }
    return false;
}
int flow(){
    int ret=0;
    trip=vector<bool>(rn,0);
    matched=vector<int>(cn,-1);
    while(true){
        bfs();
        int f=0;
        for(int i=0;i<rn;i++)
            if(!trip[i]&&dfs(i))
                f++;
        if(f==0)
            break;
        ret+=f;
    }
    return ret;
}
int main(){
    memset(ridx,-1,sizeof(ridx));
    memset(cidx,-1,sizeof(cidx));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mat[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='*'){
                if(j==0||ridx[i][j-1]==-1)
                    ridx[i][j]=rn++;
                else
                    ridx[i][j]=ridx[i][j-1];
            }
        }
    }
    for(int j=0;j<m;j++)
        for(int i=0;i<n;i++){
            if(mat[i][j]=='*'){
                if(i==0||cidx[i-1][j]==-1)
                    cidx[i][j]=cn++;
                else
                    cidx[i][j]=cidx[i-1][j];
            }
        }
    adj.resize(rn);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(mat[i][j]=='*'){
                adj[ridx[i][j]].push_back(cidx[i][j]);
            }
        }
    printf("%d\n",flow());
    return 0;
}
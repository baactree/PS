#include <bits/stdc++.h>
using namespace std;
int level[1000005];
int idx[1000005];
int matched[1000005];
int pick[1000005];
vector<int> adj[1000005];
int n;
void bfs(){
    queue<int> q;
    for(int i=0;i<n;i++)
        if(pick[i]==-1){
            q.push(i);
            level[i]=0;
        }
        else
            level[i]=-1;
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
           pick[now]=there;
           matched[there]=now;
           return true; 
        }
    }
    return false;
}
int flow(){
    int ret=0;
    memset(matched,-1,sizeof(matched));
    memset(pick,-1,sizeof(pick));
    while(true){
        bfs();
        int f=0;        
        memset(idx,0,sizeof(idx));
        for(int i=0;i<n;i++)
            if(pick[i]==-1&&dfs(i))
                f++;
        if(f==0)
            break;
        ret+=f;
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[i].push_back(a);
        adj[i].push_back(b);
    }
    int f=flow();
    if(f!=n){
        printf("-1\n");
    }
    for(int i=0;i<n;i++)
        printf("%d\n",pick[i]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int st,fi;
int n,m;
vector<int> adj[1005];
int dist[1005];
int main(){
    scanf("%d%d",&st,&fi);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist,-1,sizeof(dist));
    dist[st]=0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<adj[now].size();i++){
            int there=adj[now][i];
            if(dist[there]==-1){
                dist[there]=dist[now]+1;
                q.push(there);
            }
        }
    }
    printf("%d\n",dist[fi]);
    return 0;
}
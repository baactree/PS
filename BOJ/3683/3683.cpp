#include <bits/stdc++.h>
using namespace std;
int c,d,v;
pair<string,string> arr[500];
vector<int> adj[500];
int matched[505];
int level[505];
int trip[505];
void bfs(){
    queue<int> q;
    for(int i=0;i<v;i++){
        if(!trip[i]){
            level[i]=0;
            q.push(i);
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
int dfs(int now){
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(matched[there]==-1||(level[matched[there]]==level[now]+1&&dfs(matched[there]))){
            trip[now]=true;
            matched[there]=now;
            return true;
        }
    }
    return false;
}
int flow(){
    memset(trip,0,sizeof(trip));
    memset(matched,-1,sizeof(matched));
    int ret=0;
    while(true){
        bfs();
        int f=0;
        for(int i=0;i<v;i++)
            if(!trip[i]&&dfs(i))
                f++;
        if(f==0)
            break;
        ret+=f;
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d\n",&testcase);
    while(testcase--){
        for(int i=0;i<500;i++)
            adj[i].clear();
        scanf("%d%d%d\n",&c,&d,&v);
        for(int i=0;i<v;i++)
            cin>>arr[i].first>>arr[i].second;
        for(int i=0;i<v;i++)
            for(int j=i+1;j<v;j++){
                if(arr[i].first==arr[j].second||arr[i].second==arr[j].first){
                    if(arr[i].first[0]=='C')
                        adj[i].push_back(j);
                    else
                        adj[j].push_back(i);
                }
            }
        printf("%d\n",v-flow());
    }
    return 0;
}
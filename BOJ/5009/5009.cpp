#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1205];
vector<int> p[205];
int d[1205],s[1205];
int sn,vn;
stack<int> st;
int arr[205];
int n;
int dfs(int now){
    int ret=d[now]=vn++;
    st.push(now);
    for(int i=0;i<adj[now].size();i++){
        int there=adj[now][i];
        if(d[there]==-1)
            ret=min(ret,dfs(there));
        else if(s[there]==-1)
            ret=min(ret,d[there]);
    }
    if(ret==d[now]){
        while(true){
            int temp=st.top();
            st.pop();
            s[temp]=sn;
            if(temp==now)
                break;
        }
        sn++;
    }
    return ret;
}
bool possi(int x){
    for(int i=0;i<1205;i++)
        adj[i].clear();
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if(j==arr[i])
                continue;
            for(int k=x;k<p[i].size();k++){
                int t=p[i][k];
                if(j==arr[t])
                    continue;
                int there=t*3+j;
                int now=i*3+j;
                // (!now||!there)
                adj[now*2].push_back(there*2+1);
                adj[there*2].push_back(now*2+1);
            }
        }
        if(arr[i]==0){
            //(1||2)
            int now=i*3+1;
            int there=i*3+2;
            adj[now*2+1].push_back(there*2);
            adj[there*2+1].push_back(now*2);
        }
        else if(arr[i]==1){
            //(0||2)
            int now=i*3+0;
            int there=i*3+2;
            adj[now*2+1].push_back(there*2);
            adj[there*2+1].push_back(now*2);
        }
        else{
            //(0||1)
            int now=i*3+0;
            int there=i*3+1;
            adj[now*2+1].push_back(there*2);
            adj[there*2+1].push_back(now*2);
        }
    }
    memset(d,-1,sizeof(d));
    memset(s,-1,sizeof(s));
    sn=vn=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if(j==arr[i])
                continue;
            int now=i*3+j;
            if(d[now*2]==-1)
                dfs(now*2);
            if(d[now*2+1]==-1)
                dfs(now*2+1);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<3;j++){
            if(j==arr[i])
                continue;
            int now=i*3+j;
            if(s[now*2]==s[now*2+1])
                return false;
        }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        for(int j=0;j<n-1;j++){
            int in;
            scanf("%d",&in);
            p[i].push_back(in);
        }
    }
    int le,ri,mid,ans;
    le=0;
    ri=n-1;
    ans=-1;
    while(le<=ri){
        mid=(le+ri)/2;
        if(possi(mid)){
            ans=mid;
            ri=mid-1;
        }
        else
            le=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
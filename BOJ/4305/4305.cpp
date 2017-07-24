#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[30];
int d[30],s[30];
int sn,vn;
int arr[5];
bool check[30];
stack<int> st;
vector<vector<int> > ans;
bool cmp(const vector<int> &a,const vector<int> &b){
    return a[0]<b[0];
}
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
int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0)
            break;
        memset(check,0,sizeof(check));
        for(int i=0;i<30;i++)
            adj[i].clear();
        for(int j=0;j<n;j++){
            char in[2];
            for(int i=0;i<5;i++){
                scanf("%s",in);
                arr[i]=in[0]-'A';
                check[arr[i]]=true;
            }
            scanf("%s",in);
            int now=in[0]-'A';
            for(int i=0;i<5;i++){
                if(now==arr[i])
                    continue;
                adj[now].push_back(arr[i]);
            }
        }
        memset(d,-1,sizeof(d));
        memset(s,-1,sizeof(s));
        sn=vn=0;
        for(int i=0;i<30;i++)
            if(check[i]&&d[i]==-1)
                dfs(i);
        ans.clear();
        ans.resize(sn);
        for(int i=0;i<30;i++)
            if(check[i])
                ans[s[i]].push_back(i);
        for(int i=0;i<sn;i++)
            sort(ans[i].begin(),ans[i].end());
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<sn;i++){
            for(int j=0;j<ans[i].size();j++)
                printf("%c ",ans[i][j]+'A');
            printf("\n");
        }
        printf("\n");
    }
    return 0;  
}
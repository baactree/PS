#include <bits/stdc++.h>
using namespace std;
int n,m;
int par[1005];
vector<pair<long long,pair<int,int> > > edge;
pair<int,int> arr[1005];
int find(int x){
    if(par[x]==x)
        return x;
    return par[x]=find(par[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
        return;
    par[x]=y;
}
long long dist(pair<int,int> a,pair<int,int> b){
    long long x=a.first-b.first;
    long long y=a.second-b.second;
    return x*x+y*y; 
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        par[i]=i;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            edge.push_back({dist(arr[i],arr[j]),{i,j}});
        }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        merge(a,b);
    }
    double ans=0;
    sort(edge.begin(),edge.end());
    for(int i=0;i<edge.size();i++){
        int u=edge[i].second.first;
        int v=edge[i].second.second;
        long long w=edge[i].first;
        u=find(u);
        v=find(v);
        if(u!=v){
            ans+=sqrt(w);
            merge(u,v);
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}
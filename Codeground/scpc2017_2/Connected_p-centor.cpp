#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p;
vector<pair<int,int> > adj[100005];
int check[100005];
int cnt[100005];
int trip[100005];
ll dist[100005];
int get_cnt(int now, int par){
	cnt[now]=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par||trip[there])
			continue;
		cnt[now]+=get_cnt(there, now);
	}
	return cnt[now];
}
int get_centroid(int now, int par, int sz){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		if(there==par||trip[there])
			continue;
		if(cnt[there]>sz)
			return get_centroid(there, now, sz);
	}
	return now;
}
int get_dist(int now, int par){
	int ret=0;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
        int cost=adj[now][i].second;
		if(there==par||trip[there])
			continue;
		ret=max(ret,get_dist(there, now)+cost);
	}
    return dist[now]=ret;
}
ll solve(int now,int k){
	get_cnt(now, 0);
	int centroid=get_centroid(now, 0, cnt[now]/2);
	trip[centroid]=true;
    bool flag=false;
    //서브트리보다 k가 크므로 항상 답을 구해야함
    if(cnt[now]<k*2)
        flag=true;
    get_dist(centroid,0);
    priority_queue<pair<ll,int> > pq;
    pq.push({dist[centroid],centroid});
    ll ret=0x3f3f3f3f3f3f3f3f;
    int t=k;
    while(!pq.empty()){
        int now=pq.top().second;
        ll cost=pq.top().first;
        pq.pop();
        ret=min(ret,cost);
        t--;
        if(t==0)
            break;
        for(int i=0;i<adj[now].size();i++){
            int there=adj[now][i].first;
            int 
            pq.push({dist[there],there});
        }
    }
    if(!flag){
        set<ll> s;
        for(int i=0;i<adj[centroid].size();i++){
            int there=adj[centroid][i].first;
            int cost=adj[centroid][i].second;
            s.insert(dist[there]+cost);
        }
        for(int i=0;i<adj[centroid].size();i++){
            int there=adj[centroid][i].first;
            int cost=adj[centroid][i].second;
            if(trip[there])
                continue;
            s.erase(dist[there]+cost);
            ret=min(ret,solve(there,k)+*(--s.end()));
            s.insert(dist[there]+cost);
        }
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        scanf("%d", &n);
        for(int i=0;i<n-1;i++){
            int a, b, d;
            scanf("%d%d%d", &a,&b,&d);
            adj[a].push_back({b,d});
            adj[b].push_back({a,d});
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<adj[i].size();j++)
                printf("%d %d\n",adj[i][j].first,adj[i][j].second);
        scanf("%d",&p);
        printf("Case #%d\n%lld\n",tc,solve(1,p));
    }
	return 0;
}
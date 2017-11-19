#include <bits/stdc++.h>
using namespace std;
vector<int> adj[20005];
int n,m;
int dist[20005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(1);
	dist[1]=0;
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
	int idx,len,cnt;
	idx=cnt=len=0;
	for(int i=1;i<=n;i++){
		if(len<dist[i]){
			len=dist[i];
			idx=i;
			cnt=1;
		}
		else if(len==dist[i])
			cnt++;
	}
	printf("%d %d %d\n",idx,len,cnt);
	return 0;
}
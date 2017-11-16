#include <bits/stdc++.h>
using namespace std;
int depth[1000005];
int parent[1000005];
int arr[1005];
int n,k;
int main(){
	while(true){
		scanf("%d%d",&n,&k);
		if(n==0&&k==0)
			break;
		int root;
		scanf("%d",&root);
		queue<int> q;
		q.push(root);
		depth[root]=1;
		arr[1]=root;
		int par=-1;
		for(int i=2;i<=n;i++){
			scanf("%d",&arr[i]);
			if(arr[i]!=arr[i-1]+1){
				par=q.front();
				q.pop();
			}
			depth[arr[i]]=depth[par]+1;
			parent[arr[i]]=par;
			q.push(arr[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(parent[arr[i]]!=parent[k]&&parent[parent[arr[i]]]==parent[parent[k]]&&parent[parent[k]])
				ans++;
		}
		for(int i=1;i<=n;i++)
			depth[arr[i]]=parent[arr[i]]=0;
		printf("%d\n",ans);
	}
	return 0;
}
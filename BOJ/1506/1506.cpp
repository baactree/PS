#include <bits/stdc++.h>
using namespace std;
int n;
int mat[105][105];
int arr[105];
int sn,vn;
int s[105],d[105];
int min_v[105];
stack<int> st;
int dfs(int now){
	int ret=d[now]=vn++;
	st.push(now);
	for(int there=1;there<=n;there++){
		if(mat[now][there]){
			if(d[there]==-1)
				ret=min(ret,dfs(there));
			else if(s[there]==-1)
				ret=min(ret,d[there]);
		}
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
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%1d",&mat[i][j]);
	memset(s,-1,sizeof(s));
	memset(d,-1,sizeof(d));
	for(int i=1;i<=n;i++)
		if(d[i]==-1)
			dfs(i);
	memset(min_v,0x3f,sizeof(min_v));
	for(int i=1;i<=n;i++)
		min_v[s[i]]=min(min_v[s[i]],arr[i]);
	int ans=0;
	for(int i=0;i<sn;i++)
		ans+=min_v[i];
	printf("%d\n",ans);
	return 0;
}
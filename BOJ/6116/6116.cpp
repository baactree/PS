#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
int sum[100005];
int dp[100005];
int f[100005];
int ans[100005];
int tree[100005];
void update(int idx,int val){
	while(idx<100005){
		tree[idx]=max(tree[idx],val);
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	while(idx){
		ret=max(ret,tree[idx]);
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[n-i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+arr[i];
	vector<pair<int,int> > vec;
	vec.push_back({0,0});
	for(int i=1;i<=n;i++){
		int idx=query(i);
		int le,ri,mid,k;
		le=vec[idx].first;
		ri=vec[idx].second;
		k=-1;
		while(le<=ri){
			mid=(le+ri)/2;
			if(sum[i]>=f[mid]){
				k=mid;
				le=mid+1;
			}
			else
				ri=mid-1;
		}
		dp[i]=sum[i]-sum[k];
		f[i]=dp[i]+sum[i];
		ans[i]=ans[k]+1;
		if(f[i]>=f[i-1])
			vec.back().second++;
		else{
			int temp=lower_bound(sum,sum+n+1,f[i])-sum;
			update(temp,vec.size());
			vec.push_back({i,i});
		}
	}
	printf("%d\n",ans[n]);
	return 0;
}
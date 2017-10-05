#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct State{
	int s,e,p,q;
};
int n,k;
int arr[200005];
ll dp[25][200005];
int idx[25][200005];
int cnt[200005];
int le,ri;
ll sum;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll query(int l,int r){
	while(ri<r){
		ri++;		
		sum+=cnt[arr[ri]];
		cnt[arr[ri]]++;
	}
	while(le<l){
		cnt[arr[le]]--;
		sum-=cnt[arr[le]];
		le++;
	}
	return sum;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=k;i++){
		queue<State> qu;
		qu.push({1,n,0,n-1});
		while(!qu.empty()){
			memset(cnt,0,sizeof(cnt));
			le=1;
			ri=1;
			sum=0;
			cnt[arr[le]]++;
			int sz=qu.size();
			while(sz--){
				int s,e,p,q;
				s=qu.front().s;
				e=qu.front().e;
				p=qu.front().p;
				q=qu.front().q;
				qu.pop();
				if(s>e)
					continue;
				int mid=(s+e)/2;
				for(int k=p;k<=q&&k<mid;k++){
					ll v=dp[i-1][k]+query(k+1,mid);
					if(dp[i][mid]>v){
						dp[i][mid]=v;
						idx[i][mid]=k;
					}
				}
				qu.push({s,mid-1,p,idx[i][mid]});
				qu.push({mid+1,e,idx[i][mid],q});
			}
		}
	}
	printf("%lld\n",dp[k][n]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[100000];
int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i].first);
			arr[i].second=i;
		}
		sort(arr,arr+n,greater<pair<int,int> > ());
		long long ans=0;
		int le,ri;
		le=ri=arr[0].second;
		for(int i=1;i<n;i++){
			long long len=max(abs(le-arr[i].second),abs(ri-arr[i].second));
			ans=max(ans,len*arr[i].first);
			le=min(le,arr[i].second);
			ri=max(ri,arr[i].second);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
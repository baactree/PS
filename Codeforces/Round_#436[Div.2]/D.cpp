#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200005];
int cnt[200005];
bool chk[200005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		cnt[arr[i]]++;
	}
	int ans=0;
	priority_queue<int> pq;
	for(int i=1;i<=n;i++)
		if(!cnt[i])
			pq.push(-i);
	for(int i=0;i<n;i++){
		if(cnt[arr[i]]==1)
			continue;
		int now=0x3f3f3f3f;
		if(!pq.empty()){
			now=-pq.top();
			pq.pop();
		}
		if(!chk[arr[i]]&&arr[i]<now){
			if(now!=0x3f3f3f3f)
				pq.push(-now);
			now=arr[i];
			chk[arr[i]]=true;
			ans--;
		}
		if(!chk[arr[i]])
			cnt[arr[i]]--;
		ans++;
		arr[i]=now;
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
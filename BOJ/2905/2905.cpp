#include <bits/stdc++.h>
using namespace std;
/*
10 3
1 7 7 6 7 10 2 1 8 4
10 3
3 3 3 3 3 3 3 3 3 3
7 4
1 2 3 4 3 2 1
*/
int n,x;
int arr[1000005];
int main(){
	scanf("%d%d",&n,&x);
	long long ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		ans+=arr[i];
	}
	deque<pair<int,int> > dq;
	for(int i=0;i<x;i++){
		while(!dq.empty()&&dq.back().second>arr[i])
			dq.pop_back();
		dq.push_back({i,arr[i]});
	}
	int cnt=0;
	int pre=0;
	int h=dq.front().second;
	for(int i=x;i<=n;i++){
		while(!dq.empty()&&dq.back().second>arr[i])
			dq.pop_back();
		dq.push_back({i,arr[i]});
		if(h!=dq.front().second){
			cnt+=(i-pre-1)/x+1;
			ans-=(long long)(i-pre)*h;
			pre=i;
			h=dq.front().second;
		}
		if(dq.front().first<=i-x){
			int temp=dq.front().first;
			dq.pop_front();
			if(h!=dq.front().second){
				cnt+=(temp-pre)/x+1;
				ans-=(long long)(temp-pre+1)*h;
				pre=temp+1;
				h=dq.front().second;
			}
		}
	}
	printf("%lld\n%d\n",ans,cnt);
	return 0;
}
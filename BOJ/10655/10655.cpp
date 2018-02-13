#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[100005];
int le[100005];
int ri[100005];
int dist(pair<int,int> a,pair<int,int> b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&arr[i].first,&arr[i].second);
	for(int i=1;i<n;i++)
		le[i]=le[i-1]+dist(arr[i],arr[i-1]);
	for(int i=n-2;i>=0;i--)
		ri[i]=ri[i+1]+dist(arr[i],arr[i+1]);
	int ans=ri[0];
	for(int i=1;i<n-1;i++)
		ans=min(ans,le[i-1]+ri[i+1]+dist(arr[i-1],arr[i+1]));
	printf("%d\n",ans);
	return 0;
}
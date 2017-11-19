#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[30];
int ans[30];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i].first);
		arr[i].second=i;
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
		ans[arr[i].second]=arr[(i+1)%n].first;
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
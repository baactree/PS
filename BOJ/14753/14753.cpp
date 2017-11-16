#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int ans=-2e9;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			ans=max(ans,arr[i]*arr[j]);
			if(j<n-1){
				if(arr[i]*arr[j]<0)
					ans=max(ans,arr[i]*arr[j]*arr[j+1]);
				else
					ans=max(ans,arr[i]*arr[j]*arr[n-1]);
			}
		}
	printf("%d\n",ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int ans=0;
	int pre=-1;
	for(int i=n-1;i>=0;i--){
		if(pre==-1)
			ans++;
		pre=max(arr[i],pre);
		pre--;
	}
	printf("%d\n",ans);
	return 0;
}
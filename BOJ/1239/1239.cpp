#include <bits/stdc++.h>
using namespace std;
int n;
int arr[8];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int ans=0;
	do{
		int cnt=0;
		for(int i=0;i<n;i++){
			int sum=0;
			for(int j=0;j<n;j++){
				sum+=arr[(i+j)%n];
				if(sum==50){
					cnt++;
					break;
				}
			}
		}
		ans=max(ans,cnt/2);
	}while(next_permutation(arr,arr+n));
	printf("%d\n",ans);
	return 0;
}
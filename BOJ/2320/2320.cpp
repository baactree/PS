#include <bits/stdc++.h>
using namespace std;
int mat[16][16];
int dp[16][1<<16];
int n;
string arr[16];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(i==j)
				continue;
			if(arr[i].back()==arr[j][0])
				mat[i][j]=1;
		}
	for(int i=0;i<n;i++)
		dp[i][1<<i]=arr[i].size();
	for(int j=0;j<(1<<n);j++){
		for(int i=0;i<n;i++)
			for(int k=0;k<n;k++){
				if(mat[i][k]&&!(j&(1<<k))){
					dp[k][j|(1<<k)]=max(dp[k][j|(1<<k)],dp[i][j]+(int)arr[k].size());
				}
			}
		}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<(1<<n);j++)
			ans=max(ans,dp[i][j]);
	printf("%d\n",ans);
	return 0;
}
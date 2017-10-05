#include <bits/stdc++.h>
using namespace std;

int a[100],b[100];
char mat[2][100];
int dp[105][2][2];
int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<2;i++)
			scanf("%s",mat[i]);
		for(int i=0;i<n;i++){
			a[i]=mat[0][i]-'0';
			b[i]=(mat[1][i]=='#'?0:1);
		}
		memset(dp,-1,sizeof(dp));
		dp[0][0][0]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					if(dp[i][j][k]==-1)
						continue;
					if(i==0){
						if(!b[i])
							dp[i+1][k][0]=max(dp[i+1][k][0],dp[i][j][k]);
						dp[i+1][k][1]=max(dp[i+1][k][1],dp[i][j][k]+1);
					}
					else{
						if(!b[i]&&a[i-1]==j+k)
								dp[i+1][k][0]=max(dp[i+1][k][0],dp[i][j][k]);
						if(a[i-1]==j+k+1)
							dp[i+1][k][1]=max(dp[i+1][k][1],dp[i][j][k]+1);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				if(a[n-1]==i+j)
					ans=max(ans,dp[n][i][j]);
			}
		printf("%d\n",ans);
	}
	return 0;
}
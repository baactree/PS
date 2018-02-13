#include <bits/stdc++.h>
using namespace std;
char arr[105][5];
int n,k;
double dp[1005][105];
int mat[105][105];
double pp[105][105];
int main(){
	int testcase;
	scanf("%d",&testcase);
	while(testcase--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<=k;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=-1e14;
		int st=0;
		for(int i=0;i<n;i++){
			scanf("%s",arr[i]);
			if(strcmp(arr[i],"ICN")==0)
				st=i;
		}
		for(int i=0;i<n;i++){
			double sum=0;
			for(int j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
				sum+=mat[i][j];
				pp[i][j]=-1e14;
			}
			if(!sum)
				continue;
			for(int j=0;j<n;j++)
				pp[i][j]=log(mat[i][j]/sum);
		}
		dp[0][st]=0;
		for(int i=0;i<k;i++)
			for(int j=0;j<n;j++)
				for(int p=0;p<n;p++)
					dp[i+1][p]=max(dp[i+1][p],dp[i][j]+pp[j][p]);
		double max_v=-1e14;
		int ans=-1;
		for(int i=0;i<n;i++)
			if(max_v<dp[k][i]){
				max_v=dp[k][i];
				ans=i;
			}
		printf("%s\n",arr[ans]);
	}
	return 0;
}
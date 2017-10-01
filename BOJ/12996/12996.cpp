#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
ll dp[2][55][55][55];
int n,a,b,c;
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&c);
	dp[0][a][b][c]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=a;++j)
			for(int k=0;k<=b;++k)
				for(int p=0;p<=c;++p){
					ll &now=dp[i&1][j][k][p];
					now=0;
					int t=(i+1)&1;
					now+=dp[t][j+1][k][p];
					now+=dp[t][j][k+1][p];
					now+=dp[t][j][k][p+1];
					now+=dp[t][j+1][k+1][p];
					now+=dp[t][j+1][k][p+1];
					now+=dp[t][j][k+1][p+1];
					now+=dp[t][j+1][k+1][p+1];
					now%=mod;
				}
	printf("%d\n",dp[n&1][0][0][0]);
	return 0;
}
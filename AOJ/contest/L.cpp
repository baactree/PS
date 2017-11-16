#include <bits/stdc++.h>
using namespace std;
int n;
int dp[10][15];
int tdp[10][15];
int ans[15];
const int mod=1e9+7;
int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		int x=str[i]-'0';
		for(int j=0;j<x;j++){
			for(int k=1;k<10;k++){
				tdp[x][k+1]+=dp[j][k];
				tdp[x][k+1]%=mod;
			}
		}
		for(int k=1;k<=10;k++){
			tdp[x][k]+=dp[x][k];
			tdp[x][k]%=mod;
		}
		for(int j=x+1;j<10;j++){
			for(int k=1;k<=10;k++){
				ans[k]+=dp[j][k];
				ans[k]%=mod;
				//tdp[x][k]+=dp[j][k];
				//tdp[x][k]%=mod;
			}
		}
		tdp[x][1]++;
		tdp[x][1]%=mod;
		for(int j=0;j<10;j++)
			for(int k=0;k<15;k++){
				dp[j][k]=(dp[j][k]+tdp[j][k])%mod;
				tdp[j][k]=0;
			}
	}
	for(int i=1;i<=10;i++){
		for(int j=0;j<10;j++)
			ans[i]=(ans[i]+dp[j][i])%mod;
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int s;
string str;
const int mod=1e9+7;
int dp[3005][3005];
int sum[3005];
int main(){
    cin>>s>>str;
    dp[0][0]=1;
    for(int i=1;i<=str.size();i++){
        memset(sum,0,sizeof(sum));
        for(int j=0;j<=s;j++){
            sum[j+1]=sum[j]+dp[i-1][j];
            if(sum[j+1]>mod)
                sum[j+1]-=mod;
        }
        for(int j=0;j<=s;j++){
            dp[i][j]=(sum[j+1]-sum[max(j-25,0)]+mod);
            if(dp[i][j]>mod)
                dp[i][j]-=mod;
        }
    }
    printf("%d\n",dp[str.size()][s]);
    return 0;
}
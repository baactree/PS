#include <bits/stdc++.h>
using namespace std;
int dp[1000005][2];
int n;
string str;
int main(){
    scanf("%d",&n);
    cin>>str;
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        if(str[i-1]=='B'){
            dp[i][0]=min(dp[i-1][0]+1,dp[i-1][1]+2);
            dp[i][1]=min(dp[i-1][0]+1,dp[i-1][1]);
        }
        else{
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]+1);
            dp[i][1]=min(dp[i-1][0]+2,dp[i-1][1]+1);
        }
    }
    printf("%d\n",min(dp[n][0],dp[n][1]+1));
    return 0;
}
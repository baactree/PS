#include "bits/stdc++.h"
using namespace std;
int N,M;
int c[101];
int m[101];
int dp[101][10001];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%d",&m[i]);
    for(int i=1;i<=N;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=N;i++){
        for(int j=0;j<=10000;j++){
            if(j-c[i]>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+m[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=0;i<=10000;i++)
        if(dp[N][i]>=M)
            ans=min(ans,i);
    printf("%d\n",ans);
    return 0;
}
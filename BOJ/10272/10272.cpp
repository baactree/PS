#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[600];
double dp[600][600];
inline double dist(int x,int y){
    return hypot(arr[x].first-arr[y].first,arr[x].second-arr[y].second);
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&arr[i].first,&arr[i].second);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=2e9;
        dp[0][0]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(dp[i][j]==2e9)
                    continue;
                if(i==n-1){
                    dp[n-1][n-1]=min(dp[n-1][n-1],dp[i][j]+dist(n-1,j));
                    continue;
                }
                if(j==n-1){
                    dp[n-1][n-1]=min(dp[n-1][n-1],dp[i][j]+dist(n-1,i));
                    continue;
                }
                int next=max(i,j)+1;
                dp[next][j]=min(dp[next][j],dp[i][j]+dist(next,i));
                dp[i][next]=min(dp[i][next],dp[i][j]+dist(next,j));
            }
        printf("%.10lf\n",dp[n-1][n-1]);
    }
    return 0;
}
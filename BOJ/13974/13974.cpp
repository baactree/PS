#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[5005][5005];
int idx[5005][5005];
int arr[5005];
ll sum[5005];
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            sum[i]=sum[i-1]+arr[i];
            dp[i][i+1]=0;
            idx[i][i+1]=i;
        }
        for(int i=2;i<=n;i++)
            for(int j=1;j+i<=n+1;j++){
                // [j,j+i) 범위 답 구하기
                ll max_value=0x3f3f3f3f3f3f3f3f;
                int le=max(idx[j][j+i-1],j+1);
                int ri=min(idx[j+1][j+i],j+i-1);
                ll s=sum[j+i-1]-sum[j-1];
                for(int k=le;k<=ri;k++){
                    ll now=dp[j][k]+dp[k][j+i];
                    if(max_value>now+s){
                        max_value=now+s;
                        idx[j][j+i]=k;
                    }
                }
                dp[j][j+i]=max_value;
            }
        printf("%lld\n",dp[1][n+1]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int dp[25];
int trans[25];
int main(){
    dp[0]=dp[1]=1;
    for(int i=2;i<25;i++)
        dp[i]=dp[i-1]+dp[i-2];
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        memset(trans,0,sizeof(trans));
        int x;
        scanf("%d",&x);
        int idx=24;
        while(x){
            if(x>=dp[idx]){
                trans[idx-1]=1;
                x-=dp[idx];
            }
            idx--;
        }
        int out=0;
        for(int i=1;i<25;i++)
            out+=dp[i]*trans[i];
        printf("%d\n",out);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,q;
string str;
int dp[1505][1505][26];
int table[1505][26];
int main(){
    cin>>n>>str>>q;
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<26;k++){
                if(str[i]-'a'==k)
                    dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+1);
                else{
                    if(j<n)
                        dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+1);
                }
            }
    for(int i=0;i<=n;i++)
        for(int j=0;j<26;j++)
            for(int k=0;k<=n;k++)
                table[i][j]=max(table[i][j],dp[k][i][j]);
    while(q--){
        int m;
        char input[2];
        scanf("%d%s",&m,input);
        printf("%d\n",table[m][input[0]-'a']);
    }
    return 0;
}
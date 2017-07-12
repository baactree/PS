#include <bits/stdc++.h>
using namespace std;
int n,m;
int score[105];
int a[105];
int b[105];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&b[j]);
        int cnt=0;
        for(int j=0;j<n;j++)
            if(b[j]==a[i])
                score[j+1]++;
            else
                cnt++;
        score[a[i]]+=cnt;
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",score[i]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
int mat[100][100];
int now[100];
int calc(){
    int ret=0;
    for(int i=0;i<n;i++){
        memset(now,0,sizeof(now));
        for(int j=i;j<n;j++){
            int x=0;
            for(int k=0;k<n;k++){
                now[k]+=mat[j][k];
                x=max(0,x+now[k]);
                ret=max(ret,x);
            }
        }
    }
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&mat[i][j]);
        printf("Case #%d\n%d\n",tc,calc());
    }
    return 0;
}
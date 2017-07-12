#include <bits/stdc++.h>
using namespace std;
int n,m;
char mat[55][55];
int calc(int x,int y){
    int ret=0;
    for(int i=0;i<x;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]!='W')
                ret++;
    for(int i=x;i<y;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]!='B')
                ret++;
    for(int i=y;i<n;i++)
        for(int j=0;j<m;j++)
            if(mat[i][j]!='R')
                ret++;
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",&mat[i]);
    int ans=0x3f3f3f3f;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++){
            int cnt=calc(i,j);
            ans=min(ans,cnt);
        }
    printf("%d\n",ans);
    return 0;
}
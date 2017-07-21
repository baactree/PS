#include <bits/stdc++.h>
using namespace std;
int n,m;
int mat[500][500];
int calc(int x){
    int ret=0;
    while(x){
        ret+=(x%10)==9;
        x/=10;
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            mat[i][j]=calc(x);
            ans+=mat[i][j];
        }
    int max_value=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++)
            sum+=mat[i][j];
        max_value=max(max_value,sum);
    }
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=mat[i][j];
        max_value=max(max_value,sum);
    }
    printf("%d\n",ans-max_value);
    return 0;
}
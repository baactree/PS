#include <bits/stdc++.h>
using namespace std;
int k,n,m;
int a[1000];
int b[1000];
int pa[2000005];
int pb[2000005];
int main(){
    scanf("%d%d%d",&k,&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<n;i++){
        int t=0;
        for(int j=0;j<n-(i!=0);j++){
            t+=a[(i+j)%n];
            pa[t]++;
        }
    }
    for(int i=0;i<m;i++){
        int t=0;
        for(int j=0;j<m-(i!=0);j++){
            t+=b[(i+j)%m];
            pb[t]++;
        }
    }
    long long ans=0;
    pa[0]=pb[0]=1;
    for(int i=0;i<=k;i++){
        ans+=(long long)pa[i]*pb[k-i];
    }
    printf("%lld\n",ans);
    return 0;
}
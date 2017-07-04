#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000005];
int le[1000005];
int ri[1000005];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        if(i==1)
            le[i]=arr[i];
        else
            le[i]=gcd(arr[i],le[i-1]);
        if(i==n)
            ri[n+1-i]=arr[n+1-i];
        else
            ri[n+1-i]=gcd(arr[n+1-i],ri[n-i+2]);
    }
    int ans=-1;
    int idx;
    for(int i=1;i<=n;i++){
        int g;
        if(i==1)
            g=ri[i+1];
        else if(i==n)
            g=le[i-1];
        else   
            g=gcd(le[i-1],ri[i+1]);
        if(arr[i]%g==0)
            continue;
        if(ans<g){
            idx=arr[i];
            ans=g;
        }
    }
    if(ans!=-1)
        printf("%d %d\n",ans,idx);
    else
        printf("-1\n");
    return 0;
}
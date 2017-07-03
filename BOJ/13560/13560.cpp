#include <bits/stdc++.h>
using namespace std;
int n;
int w[10000];
int l[10000];
int t[10000];
bool possi(int sum){
    if(sum*2!=n*(n-1))
        return false;
    for(int i=n-1;i>=0;i--){
        memset(t,0,sizeof(t));
        for(int j=n-1;j>0;j--){
            int k=min(l[j],w[i]);
            l[j]-=k;
            w[i]-=k;
            t[j-1]+=k;
            if(w[i]==0)
                break;
        }
        if(w[i]!=0)
            return false;
        for(int j=0;j<n;j++)
            l[j]+=t[j];
    }
    for(int i=1;i<n;i++)
        if(l[i]!=0)
            return false;
    return true;
}
int main(){
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        l[n-1-w[i]]++;
        sum+=w[i];
    }
    sort(w,w+n);
    printf("%d\n",possi(sum)?1:-1);
    return 0;
}
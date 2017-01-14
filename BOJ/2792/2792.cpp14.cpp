#include "bits/stdc++.h"
using namespace std;
int arr[3000000];
int N,M;
bool possi(int num){
    int ret=0;
    for(int i=0;i<M;i++)
        ret=min(N+1,ret+arr[i]/num+(arr[i]%num!=0));
    return ret<=N;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++)
        scanf("%d",&arr[i]);
    int le,ri,mid;
    le=0;ri=1e9;
    int ans;
    while(ri>=le){
        mid=(le+ri)/2;
        if(possi(mid)){
            ans=mid;
            ri=mid-1;
        }
        else
            le=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
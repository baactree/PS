#include "bits/stdc++.h"
using namespace std;
int N,S;
pair<int,int> arr[300000];
int cache[300000];
int solve(int idx){
    if(idx==N)
        return 0;
    int &ret=cache[idx];
    if(ret!=-1)
        return ret;
    ret=solve(idx+1);
    int le,ri,mid;
    le=idx,ri=N-1;
    int nidx=N;
    while(ri>=le){
        mid=(le+ri)/2;
        if(arr[mid].first>=arr[idx].first+S){
            ri=mid-1;
            nidx=mid;
        }
        else
            le=mid+1;
    }
    ret=max(ret,solve(nidx)+arr[idx].second);
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d%d",&N,&S);
    for(int i=0;i<N;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr,arr+N);
    int le,ri,mid;
    le=0;
    ri=N-1;
    int idx=N;
    while(ri>=le){
        mid=(le+ri)/2;
        if(arr[mid].first>=S){
            idx=mid;
            ri=mid-1;
        }
        else 
            le=mid+1;
    }
    printf("%d\n",solve(idx));
    return 0;
}
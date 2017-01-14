#include "bits/stdc++.h"
using namespace std;
pair<int,int> arr[10000];
int cache[10000];
int N;
int solve(int idx){
    if(idx==N)
        return 0;
    int &ret=cache[idx];
    if(ret!=-1)
        return ret;
    ret=0x3f3f3f3f;
    int max_hight=0;
    for(int i=idx;i<N;i++){
        max_hight=max(max_hight,abs(arr[i].second));
        int width=max(max_hight*2,arr[i].first-arr[idx].first);
        ret=min(ret,solve(i+1)+width);
    }
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr,arr+N);
    printf("%d\n",solve(0));
    return 0;
}
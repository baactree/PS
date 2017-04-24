#include <bits/stdc++.h>
using namespace std;
int n,k;
pair<int,int> arr[10000];
bool possi(int x){
    int min_value=arr[0].second;
    int max_value=arr[0].second;
    int cnt=1;
    for(int i=1;i<n;i++){
        min_value=min(min_value,arr[i].second);
        max_value=max(max_value,arr[i].second);
        if(abs(max_value-min_value)<=x)
            continue;
        else{
            cnt++;
            min_value=arr[i].second;
            max_value=arr[i].second;
        }
    }
    return cnt<=k;
}
int main(){
    int TestCase;
    scanf("%d",&TestCase);
    while(TestCase--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d%d",&arr[i].first,&arr[i].second);
        }
        if(k>=n){
            printf("0.0\n");
            continue;
        }
        sort(arr,arr+n);
        int le,ri,mid;
        int ans;
        le=0,ri=4e8;
        while(le<=ri){
            mid=(le+ri)/2;
            if(possi(mid)){
                ans=mid;
                ri=mid-1;
            }
            else
                le=mid+1;
        }
        printf("%.1lf\n",ans/2.);
    }
    return 0;
}
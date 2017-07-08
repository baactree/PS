#include <bits/stdc++.h>
using namespace std;
int n,t;
int arr[100000];
vector<int> possi(int x){
    long long cnt=0;
    vector<int> ret(n);
    for(int i=0;i<n;i++)
        ret[i]=arr[i];
    for(int i=0;i<n-1;i++)
        if(ret[i]+x<ret[i+1]){
            cnt+=ret[i+1]-(ret[i]+x);
            ret[i+1]=ret[i]+x;
        }
    for(int i=n-1;i>0;i--){
        if(ret[i]+x<ret[i-1]){
            cnt+=ret[i-1]-(ret[i]+x);
            ret[i-1]=ret[i]+x;
        }
    }
    if(cnt>t)
        return vector<int>();
    return ret;
}
int main(){
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int le,ri,mid;
    vector<int> ans;
    le=0;
    ri=1e9;
    while(le<=ri){
        mid=(le+ri)/2;
        vector<int> ret=possi(mid);
        if(!ret.empty()){
            ans=ret;
            ri=mid-1;
        }    
        else
            le=mid+1;
    }
    for(int i=0;i<n;i++)
        printf("%d ", ans[i]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n;
pair<int,int> arr[500005];
int dist(const pair<int,int> &a,const pair<int,int> &b){
    int x=a.first-b.first;
    int y=a.second-b.second;
    return x*x+y*y;
}
int es(int le,int ri){
    int ret=inf;
    for(int i=le;i<=ri;i++)
        for(int j=i+1;j<=ri;j++)
            ret=min(ret,dist(arr[i],arr[j]));
    return ret;
}
int solve(int le,int ri){
    int sz=ri-le+1;
    if(sz<=3)
        return es(le,ri);
    int mid=(le+ri)/2;
    int left_ret=solve(le,mid);
    int right_ret=solve(mid+1,ri);
    int ret=min(left_ret,right_ret);
    vector<pair<int,int> > vec;
    for(int i=le;i<=ri;i++){
        int d=arr[mid].first-arr[i].first;
        if(d*d<ret)
            vec.push_back({arr[i].second,arr[i].first});
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
        for(int j=i+1;j<vec.size();j++){
            int d=vec[j].first-vec[i].first;
            if(d*d<ret)
                ret=min(ret,dist(arr[i],arr[j]));
            else
                break;
        }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr,arr+n);
    printf("%d\n",solve(0,n-1));
    return 0;
}
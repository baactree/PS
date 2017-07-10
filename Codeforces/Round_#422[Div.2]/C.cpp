#include <bits/stdc++.h>
using namespace std;
struct Node{
    int l,r,c;
};
int n,x;
Node arr[200005];
vector<pair<int,int> > r[200005];
vector<pair<int,int> > l[200005];
vector<int> rmin[200005];
vector<int> lmin[200005];
int main(){
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].l,&arr[i].r,&arr[i].c);
        int d=arr[i].r-arr[i].l+1;
        r[d].push_back({arr[i].r,arr[i].c});
        l[d].push_back({arr[i].l,arr[i].c});
    }
    for(int i=0;i<200005;i++){
        sort(r[i].begin(),r[i].end());
        rmin[i].resize(r[i].size());
        for(int j=0;j<rmin[i].size();j++){
            if(j==0)
                rmin[i][j]=r[i][j].second;
            else
                rmin[i][j]=min(rmin[i][j-1],r[i][j].second);
        }
        sort(l[i].begin(),l[i].end());
        lmin[i].resize(l[i].size());
        int len=l[i].size();
        for(int j=len-1;j>=0;j--){
            if(j==len-1)
                lmin[i][j]=l[i][j].second;
            else
                lmin[i][j]=min(lmin[i][j+1],l[i][j].second);
        }
    }
    int ans=2e9+5;
    for(int i=0;i<n;i++){
        int nl=arr[i].l;
        int nr=arr[i].r;
        int c=arr[i].c;
        int d=x-(nr-nl+1);
        if(d<1)
            continue;
        int ridx=lower_bound(r[d].begin(),r[d].end(),make_pair(nl,0))-r[d].begin();
        if(ridx!=0){
            ridx--;
            ans=min(ans,c+rmin[d][ridx]);
        }
        int lidx=upper_bound(l[d].begin(),l[d].end(),make_pair(nr,(int)2e9))-l[d].begin();
        if(lidx!=l[d].size()){
            ans=min(ans,c+lmin[d][lidx]);
        }
    }   
    if(ans==2e9+5)
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}
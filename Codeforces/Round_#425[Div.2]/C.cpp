#include <bits/stdc++.h>
using namespace std;
const long double eps=1e-1;
int n,s;
vector<pair<int,int> > l,r;
typedef long long ll;
typedef long double ld;
bool possi(ld x){
   // printf("%.5Lf ",x);
    vector<pair<pair<int,int>,int> > vec;
    int cnt[2]={0,};
    for(int i=0;i<l.size();i++){
        int d=l[i].first;
        int v=l[i].second;
        if(d<=x*v){
            cnt[0]++;
            continue;
        }
        if(d>(v+s)*x)
            continue;
        ld p=(x*(v+s)-d)/s;
        //printf("%.5Lf ",p);        
        int xl=d;
        int xr=min(1000000ll,d+(ll)(p*(s-v)));
        vec.push_back({{xl,0},0});
        vec.push_back({{xr,1},0});
    }
    for(int i=0;i<r.size();i++){
        int d=1000000-r[i].first;
        int v=r[i].second;
        if(d<=x*v){
            cnt[1]++;
            continue;
        }
        if(d>(v+s)*x)
            continue;
        ld p=(x*(v+s)-d)/s;
        //printf("%.5Lf ",p);
        int xl=max(0ll,r[i].first-(ll)(p*(s-v)));
        int xr=r[i].first;
        vec.push_back({{xl,0},1});
        vec.push_back({{xr,1},1});
    }
    if(cnt[0]>0&&cnt[1]>0)
        return true;
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        int y=vec[i].first.second;
        int z=vec[i].second;
        if(y)
            cnt[z]--;
        else
            cnt[z]++;
        if(cnt[0]>0&&cnt[1]>0)
            return true;
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++){
        int x,v,t;
        scanf("%d%d%d",&x,&v,&t);
        if(t==1)
            l.push_back({x,v});
        else
            r.push_back({x,v});
    }
    ld le,ri,mid;
    le=0;
    ri=1e6;
    for(int i=0;i<100;i++){
        mid=(le+ri)/2;
        if(possi(mid)){
            //cout<<"pass"<<endl;
            ri=mid;
        }
        else{
            //cout<<"fail"<<endl;
            le=mid;
        }
    }
    printf("%.20Lf\n",ri);
    return 0;
}
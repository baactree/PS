#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[2000005];
bool prime[2000005];
vector<int> p;
typedef long long ll;
int main(){
    for(int i=2;i<=2000000;i++){
        if(!prime[i]){
            p.push_back(i);
            for(int j=i+i;j<=2000000;j+=i){
                prime[j]=true;
            }
        }
    }
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        vector<pair<int,int> > vec;
        for(int i=0;i<p.size()&&(ll)p[i]*p[i]<=x;i++){
            int cnt=0;
            while(x%p[i]==0){
                cnt++;
                x/=p[i];
            }
            if(cnt!=0)
                vec.push_back({p[i],cnt});
        }
        if(x!=1)
            vec.push_back({x,1});
        vector<int> d;
        d.push_back(1);
        cnt[1]++;
        for(int i=0;i<vec.size();i++){
            int sz=d.size();
            int r=1;
            for(int j=0;j<vec[i].second;j++){
                r*=vec[i].first;
                for(int k=0;k<sz;k++){
                    d.push_back(d[k]*r);
                    cnt[d[k]*r]++;
                }
            }
        }
    }
    long long ans=-1;
    for(long long i=1;i<=2000000;i++){
        if(cnt[i]<2)
            continue;
        ans=max(ans,cnt[i]*i);
    }
    cout<<ans<<endl;
    return 0;
}
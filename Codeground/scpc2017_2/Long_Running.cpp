#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s[5];
ll l[5];
ll d[5];
//ax+by=c

pair<ll,pair<ll,ll> > gcd(ll a,ll b){
    deque<ll> r,s,t;
    r.push_back(a);
    r.push_back(b);
    s.push_back(1);
    s.push_back(0);
    t.push_back(0);
    t.push_back(1);
    while(r.back()){
        ll q=r[0]/r[1];
        r.push_back(r[0]-q*r[1]);
        s.push_back(s[0]-q*s[1]);
        t.push_back(t[0]-q*t[1]);
        r.pop_front();
        s.pop_front();
        t.pop_front();
    }
    return {r.front(),{s.front(),t.front()}};
}

pair<ll,ll> calc(ll a,ll b,ll c){
    a*=-1;
    auto g=gcd(a,b);
    if(c%g.first!=0)
        cout<<"Invalid Input\n";
    ll k=c/g.first;
    ll x=k*g.second.first;
    ll y=k*g.second.second;
    ll p=(b/g.first);
    ll q=(a/g.first);
    if(x<=0){
        ll t=(-x)/p;
        x+=t*p;
        y-=t*q;
    }
    else{
        ll t=(x+p-1)/p;
        x-=t*p;
        y+=t*q;
    }
    return {-x,p};
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        vector<pair<ll,ll> > vec;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld%lld%lld",&s[i],&l[i],&d[i]);
            if(d[i]==0){
                ll lcm=l[i]/gcd(l[i],s[i]).first;
                vec.push_back({0,lcm});
            }
            else
                vec.push_back(calc(-s[i],l[i],d[i]));
        }
        for(int i=1;i<n;i++){
            ll a=vec[i-1].second;
            ll c=vec[i-1].first;
            ll b=vec[i].second;
            ll d=vec[i].first;
            if(c-d==0)
                vec[i]={c,b/gcd(a,b).first*a};
            else if(c>d){
                auto temp=calc(-a,b,c-d);
                ll now=a*temp.first+c;
                vec[i]={now,temp.second*a};
            }
            else{
                auto temp=calc(-b,a,d-c);
                ll now=b*temp.first+d;
                vec[i]={now,temp.second*b};
            }
        }
        printf("Case #%d\n",tc);
        printf("%lld\n",vec.back().first==0?vec.back().second:vec.back().first);
    }
    return 0;
}
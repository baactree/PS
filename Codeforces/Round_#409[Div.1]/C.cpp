#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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


int n,m;
bool a[200005];
vector<int> s[200005];
vector<int> d;
int cache[200005];
int solve(int now){
    if(s[now].empty())
        return 0;
    int &ret=cache[now];
    if(ret!=-1)
        return ret;
    ret=s[now].size();
    for(int i=0;i<d.size();i++){
        if(d[i]>now&&d[i]%now==0)
            ret=max(ret,(int)s[now].size()+solve(d[i]));
    }
    return ret;
}
int calc(int a,int b){
    if(b==0)
        return 0;
    if(a==1)
        return b;
    auto g=gcd(a,m);
    int k=b/g.first;
    ll x,y;
    x=g.second.first*k;
    y=g.second.second*k;
    ll t=m/g.first;
    if(x>0){
        ll p=x/t;
        x-=p*t;
    }
    else{
        ll p=(-x+t-1)/t;
        x+=p*t;
    }
    return x;
}
void get_ans(int now,int pre,vector<int> &arr){
    if(s[now].empty())
        return;
    for(int i=0;i<s[now].size();i++){
        int c=calc(pre,s[now][i]);
        arr.push_back(c);
        pre=s[now][i];
    }
    int max_value=-1;
    int idx=-1;
    for(int i=0;i<d.size();i++){
        if(d[i]>now&&d[i]%now==0){
            if(max_value<solve(d[i])){
                max_value=solve(d[i]);
                idx=i;
            }
        }
    }
    if(idx!=-1)
        get_ans(d[idx],pre,arr);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]=true;
    }
    for(int i=0;i<m;i++){
        if(a[i])
            continue;
        int g=gcd(m,i).first;
        s[g].push_back(i);
    }
    for(int i=1;i<=m;i++)
        if(!s[i].empty())
            d.push_back(i);
    memset(cache,-1,sizeof(cache));
    int ans=0;
    for(int i=1;i<=m;i++)
        ans=max(ans,solve(i));
    printf("%d\n",ans);
    vector<int> arr;
    for(int i=1;i<=m;i++)
        if(solve(i)==ans){
            get_ans(i,1,arr);
            break;
        }
    for(int i=0;i<arr.size();i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
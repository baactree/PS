#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
typedef long long ll;
struct Circle{
    ll a,b,r;
    Circle(){}
    Circle(ll a,ll b,ll r):a(a),b(b),r(r){}
    bool in(const Circle &rhs)const{
        ll x=rhs.a-a;
        ll y=rhs.b-b;
        return x*x+y*y<=r*r&&rhs.r<=r;
    }
};
int n;
Circle arr[1000];
int in[1000];
vector<int> adj[1000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].r);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(arr[i].in(arr[j])){
                adj[i].push_back(j);
                in[j]++;
            }
        }
    double ans=0;
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++){
        if(in[i]==0)
            q.push({i,0});
    }
    while(!q.empty()){
        int now=q.front().first;
        int mode=q.front().second;
        q.pop();
        double r=arr[now].r*arr[now].r*pi;
        if(mode<2)
            ans+=r;
        else{
            mode-=2;
            if(mode)
                ans+=r;
            else 
                ans-=r;
        }
        for(int i=0;i<adj[now].size();i++){
            int there=adj[now][i];
            in[there]--;
            if(in[there]==0){
                int next=0;
                if(mode>1){
                    mode-=2;
                    next=1-mode;
                    next+=2;
                }
                else{
                    next=mode+1;
                }
                q.push({there,next});
            }
        }
    }
    printf("%.10lf\n",ans);
    return 0;
}
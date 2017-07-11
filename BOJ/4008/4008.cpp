#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000005];
ll s[1000005];
vector<int> line;
int a,b,c;
int n;
double calc(int x,int y){
    ll a1=-2*a*s[x];
    ll b1=a*s[x]*s[x]-b*s[x]+dp[x];
    ll a2=-2*a*s[y];
    ll b2=a*s[y]*s[y]-b*s[y]+dp[y];
    return (b1-b2)/(a2-a1);
}
int main(){
    scanf("%d",&n);
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }
    int idx=0;
    for(int i=1;i<=n;i++){
        dp[i]=a*s[i]*s[i]+b*s[i]+c;
        if(!line.empty()){
            while(idx+1<line.size()&&calc(line[idx],line[idx+1])<s[i])
                idx++;
            int j=line[idx];
            ll k=s[i]-s[j];
            dp[i]=max(dp[i],dp[j]+a*k*k+b*k+c);
        }
        while(line.size()>1
        &&calc(line[line.size()-1],i)<calc(line[line.size()-2],line[line.size()-1]))
            line.pop_back();
        line.push_back(i);
    }
    printf("%lld\n",dp[n]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,k;
// d(h,w) = 높이가 h 너비가 w인 그리드를 채우는 방법의수
// d(h,w) = d(h-1,w)*f(w) + sum(f(i)*d(h-1,i)*d(h,w-1-i)) // (0<=i<w)
// d(0,w) = 1
// d(h,0) = 1
ll d[305][305];
// f(x) = 길이가 x인 연속한 서로 다른 블럭을 만드는 방법의수
// f(0) = 1
ll f[305];
// g(x,k) = 길이가 x이고 마지막으로 고른 색이 k인 서로다른 블럭을 만드는 방법의 수
// g(0,0) = 1
ll g[305][305];
// color x가 가능한 길이
bool color[305][305];
ll solve(int h,int w){
    if(h==0||w==0)
        return 1;
    ll &ret=d[h][w];
    if(ret!=-1)
        return ret;
    ret=(solve(h-1,w)*f[w])%mod;
    for(int i=0;i<w;i++)
        ret=(ret+(((f[i]*solve(h-1,i))%mod)*solve(h,w-1-i))%mod)%mod;
    return ret;
}
int main(){
    scanf("%d%d%d",&k,&m,&n);
    for(int i=1;i<=k;i++)
        color[i][0]=true;
    for(int i=1;i<=k;i++){
        int in;
        scanf("%d",&in);
        for(int j=0;j<=m;j++)
            if(color[in][j]){
                for(int p=1;p*i+j<=m;p++)
                    color[in][p*i+j]|=true;
            }
    }
    g[0][0]=1;
    f[0]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=k;j++){
            for(int p=1;p<=m&&i-p>=0;p++){
                if(color[j][p]){
                    g[i][j]=(g[i][j]+f[i-p])%mod;
                    g[i][j]=(g[i][j]-g[i-p][j]+mod)%mod;
                }
            }
        }
        for(int j=1;j<=k;j++)
            f[i]=(f[i]+g[i][j])%mod;
    }
    memset(d,-1,sizeof(d));
    printf("%lld\n",solve(n,m));
    return 0;
}
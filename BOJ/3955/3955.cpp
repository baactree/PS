#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,c;
// 디오판토스 방정식
// ax+by=c
// (a,b)|c 인 경우에만 해가 존재 (필요충분조건)
// ax+by=(a,b)의 해를 x0,y0라고 하고
// c=k*(a,b) 라고 할 때
// 초기해는 k*x0, k*y0이다
// 일반해는 k*(x0+b/(a,b)), k*(y0-a/(a,b)) 이다
//
// 확장된 유클리드 호제법
// ax+by=(a,b)의  {(a,b),{x0,y0}} 리턴
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
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d%d",&k,&c);
        auto g=gcd(k,c);
        if(g.first!=1){
            printf("IMPOSSIBLE\n");
        }
        else{
            //초기해
            ll x=g.second.first;
            ll y=g.second.second;
            //x+c , y-k 일반해
            //x<0 and y>0 and y<=1e9
            
            //가능해 영역으로 shift
            if(x>=0){
                ll t=x/c+1;
                x-=t*c;
                y+=t*k;
            }
            //y가 자연수가 아닌경우
            if(y<=0){
                ll t=(-y)/k+1;
                x-=t*c;
                y+=t*k;
            }
            else if(y>1e9){
                printf("IMPOSSIBLE\n");
                continue;
            }
            printf("%lld\n",y);
        }
    }
    return 0;
}
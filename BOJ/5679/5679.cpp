#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h;
int main(){
    while(true){
        scanf("%lld",&h);
        if(h==0)
            break;
        ll ans=h;
        while(h!=1){
            ans=max(ans,h);
            if(h&1)
                h=3*h+1;
            else h/=2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool check[1000005];
vector<int> p;
typedef long long ll;
bool possi(ll s){
    for(int i=0;i<p.size();i++)
        if(s%p[i]==0)
            return false;
    return true;
}
int main(){
    for(ll i=2;i<=1000000;i++){
        if(check[i])
            continue;
        p.push_back(i);
        for(ll j=i*i;j<=1000000;j+=i)
            check[j]=true;
    }
    int n;
    scanf("%d",&n);
    while(n--){
        ll s;
        scanf("%lld",&s);
        printf("%s\n",possi(s)?"YES":"NO");
    }
    return 0;
}
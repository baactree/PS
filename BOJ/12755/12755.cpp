#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int i,r;
    for(i=1,r=1;n>9*r*i;i++,r*=10)
        n-=9*r*i;
    n--;
    int p,q;
    p=n/i;
    q=n%i;
    r+=p;
    cout<<to_string(r)[q]<<endl;
    return 0;
}
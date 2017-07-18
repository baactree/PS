#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int p[50];
int c[50]; 
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&p[i]);
        for(int i=1;i<=n;i++){
            k-=p[c[i]];
        }
        printf("Case #%d\n%s\n",tc,k>=0?"Y":"N");
    }
    return 0;
}
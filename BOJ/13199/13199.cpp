#include <bits/stdc++.h>
using namespace std;
int P,M,F,C;
int main(){
    int Case;
    scanf("%d",&Case);
    while(Case--){
        scanf("%d%d%d%d",&P,&M,&F,&C);
        int s,d;
        int sc,dc;
        s=d=M/P;
        sc=dc=s*C;
        d+=dc/F; 
        while(sc>=F){
            int m=sc/F;
            sc=sc%F;
            sc+=m*C;
            s+=m;
        }
        printf("%d\n",s-d);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
double t;
int loc[50000];
int sp[50000];
int main(){
    scanf("%d%lf",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&loc[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&sp[i]);
    double le,ri;
    le=1;
    ri=1e9;
    for(int i=0;i<n;i++){
        double l=max(1.0,loc[i]-sp[i]*t);
        double r=min(1e9,loc[i]+sp[i]*t);
        le=max(le,l);
        ri=min(ri,r);
    }
    printf("%d\n",le<=ri);
    return 0;
}
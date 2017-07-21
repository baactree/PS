#include <bits/stdc++.h>
using namespace std;
int n;
int par[20005];
int dist[20005];
char order[3];
int find(int x){
    if(x==par[x])
        return x;
    int p=find(par[x]);
    dist[x]+=dist[par[x]];
    return par[x]=p;
}
//x->y
void merge(int x,int y){
    int d=abs(x-y)%1000;
    par[x]=y;
    dist[x]+=d;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            par[i]=i;
            dist[i]=0;
        }
        while(scanf("%s",order)!=EOF){
            if(order[0]=='O')
                break;
            if(order[0]=='E'){
                int a;
                scanf("%d",&a);
                int b=find(a);
                printf("%d\n",dist[a]);
            }
            else{
                int a,b;
                scanf("%d%d",&a,&b);
                merge(a,b);
            }
        }
    }
    return 0;
}
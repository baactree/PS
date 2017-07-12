#include <bits/stdc++.h>
using namespace std;
string a,b,c;
int cache[205][205];
int solve(int aidx,int bidx,int cidx){
    if(cidx==c.size())
        return 1;
    int &ret=cache[aidx][bidx];
    if(ret!=-1)
        return ret;
    ret=0;
    if(aidx!=a.size()&&a[aidx]==c[cidx])
        ret|=solve(aidx+1,bidx,cidx+1);
    if(bidx!=b.size()&&b[bidx]==c[cidx])
        ret|=solve(aidx,bidx+1,cidx+1);
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        cin>>a>>b>>c;
        memset(cache,-1,sizeof(cache));
        printf("Data set %d: %s\n",tc,solve(0,0,0)?"yes":"no");
    }
    return 0;
}
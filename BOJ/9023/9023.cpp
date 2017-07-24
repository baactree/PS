#include <bits/stdc++.h>
using namespace std;
int C,D,d;
vector<int> a;
vector<int> b;
int cache[105][105][2][2];
int solve(int aidx,int bidx,int apre,int bpre){
    if(aidx==a.size()&&bidx==b.size())
        return 0;
    int &ret=cache[aidx][bidx][apre][bpre];
    if(ret!=-1)
        return ret;
    ret=0x3f3f3f3f;
    if(aidx<a.size()&&bidx<b.size()){
        if(a[aidx]==b[bidx])
            ret=min(ret,solve(aidx+1,bidx+1,0,0)+C);
        else
            ret=min(ret,solve(aidx+1,bidx+1,0,0)+C*2);
    }
    if(aidx<a.size())
        ret=min(ret,solve(aidx+1,bidx,0,1)+(bpre?d:D+d)+C);
    if(bidx<b.size())
        ret=min(ret,solve(aidx,bidx+1,1,0)+(apre?d:D+d)+C);
    return ret;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d%d%d",&C,&D,&d);
        a.clear();
        b.clear();
        while(true){
            int in;
            scanf("%d",&in);
            if(in==0)
                break;
            a.push_back(in);
        }
        while(true){
            int in;
            scanf("%d",&in);
            if(in==0)
                break;
            b.push_back(in);
        }
        memset(cache,-1,sizeof(cache));
        printf("%d\n",solve(0,0,0,0));
    }
    return 0;
}
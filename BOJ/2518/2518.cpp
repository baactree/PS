#include <bits/stdc++.h>
using namespace std;
int n;
int f[100];
int m[100];
int h[100];
int fs,ms,hs;
int cache[105][105][105][4];
const int inf=0x3f3f3f3f;
int solve(int fidx,int midx,int hidx,int pick){
    if(fidx==fs&&midx==ms&&hidx==hs)
        return 0;
    int &ret=cache[fidx][midx][hidx][pick];
    if(ret!=-1)
        return ret;
    ret=inf;
    int now;
    if(pick==0)
        now=0;
    else if(pick==1)
        now=f[fidx-1];
    else if(pick==2)
        now=m[midx-1];
    else
        now=h[hidx-1];
    int rm=inf;
    int ridx=0;
    if(fidx!=fs){
        int temp=(f[fidx]-now+n)%n;
        if(rm>temp){
            rm=temp;
            ridx=1;
        }
    }
    if(midx!=ms){
        int temp=(m[midx]-now+n)%n;
        if(rm>temp){
            rm=temp;
            ridx=2;
        }
    }
    if(hidx!=hs){
        int temp=(h[hidx]-now+n)%n;
        if(rm>temp){
            rm=temp;
            ridx=3;
        }
    }
    int lm=inf;
    int lidx=0;
    if(fidx!=fs){
        int temp=(now-f[fidx]+n)%n;
        if(lm>temp){
            lm=temp;
            lidx=1;
        }
    }
    if(midx!=ms){
        int temp=(now-m[midx]+n)%n;
        if(lm>temp){
            lm=temp;
            lidx=2;
        }
    }
    if(hidx!=hs){
        int temp=(now-h[hidx]+n)%n;
        if(lm>temp){
            lm=temp;
            lidx=3;
        }
    }
    if(ridx==1)
        ret=min(ret,solve(fidx+1,midx,hidx,1)+rm);
    else if(ridx==2)
        ret=min(ret,solve(fidx,midx+1,hidx,2)+rm);
    else
        ret=min(ret,solve(fidx,midx,hidx+1,3)+rm);
    if(lidx==1)
        ret=min(ret,solve(fidx+1,midx,hidx,1)+lm);
    else if(lidx==2)
        ret=min(ret,solve(fidx,midx+1,hidx,2)+lm);
    else
        ret=min(ret,solve(fidx,midx,hidx+1,3)+lm);
    return ret;
}
int main(){
    scanf("%d",&n);
    int k;
    int t=n/3;
    scanf("%d",&k);
    fs=k;
    for(int i=0;i<k;i++){
        scanf("%d",&f[i]);
        f[i]--;
    }
    scanf("%d",&k);
    ms=k;
    for(int i=0;i<k;i++){
        scanf("%d",&m[i]);
        m[i]--;
        m[i]=(m[i]-t+n)%n;
    }
    scanf("%d",&k);
    hs=k;
    for(int i=0;i<k;i++){
        scanf("%d",&h[i]);
        h[i]--;
        h[i]=(h[i]-t*2+n)%n;
    }
    memset(cache,-1,sizeof(cache));
    printf("%d\n",solve(0,0,0,0));
    return 0;
}
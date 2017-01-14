#include "bits/stdc++.h"
using namespace std;
string X,Y;
int lx,ly;
int cache[3006][3006];
int A,B,C;
int calc(char a,char b){
    if(a==' '||b==' ')
        return B;
    if(a==b)
        return A;
    return C;
}
int solve(int xidx,int yidx){
    if(xidx==lx&&yidx==ly)
        return 0;
    int &ret=cache[xidx][yidx];
    if(ret!=0x3f3f3f3f)
        return ret;
    ret=-0x3f3f3f3f;
    if(yidx!=ly)
        ret=max(ret,solve(xidx,yidx+1)+calc(' ',Y[yidx]));
    if(xidx!=lx)
        ret=max(ret,solve(xidx+1,yidx)+calc(X[xidx],' '));
    if(xidx!=lx&&yidx!=ly)
        ret=max(ret,solve(xidx+1,yidx+1)+calc(X[xidx],Y[yidx]));
    return ret;
}
int main(){
    memset(cache,0x3f,sizeof(cache));
    scanf("%d%d%d",&A,&B,&C);
    cin>>X>>Y;
    lx=X.size();
    ly=Y.size();
    printf("%d\n",solve(0,0));
    return 0;
}
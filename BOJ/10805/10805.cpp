#include <bits/stdc++.h>
using namespace std;
int cache[51][51][51][51];
int solve(int h1,int w1,int h2,int w2){
    if(w1==0||h1==0)
        return 0;
    if(h2==0||w2==0){
        if(h1==1)
            return w1;
        if(w1==1)
            return h1;
        if(h1==w1)
            return 1;
        int &ret=cache[h1][w1][h2][w2];
        if(ret!=-1)
            return ret;
        ret=0x3f3f3f3f;
        for(int i=1;i<w1;i++)
            ret=min(ret,solve(h1,i,0,0)+solve(h1,w1-i,0,0));
        swap(h1,w1);
        for(int i=1;i<w1;i++)
            ret=min(ret,solve(h1,i,0,0)+solve(h1,w1-i,0,0));
        return ret;
    }
    int &ret=cache[h1][w1][h2][w2];
    if(ret!=-1)
        return ret;
    ret=0x3f3f3f3f;
    int k=w1-w2;
    for(int i=1;i<w1;i++){
        if(i<k){
            ret=min(ret,solve(h1,i,0,0)+solve(h1,w1-i,h2,w2));
        }
        else if(i==k){
            ret=min(ret,solve(h1,k,0,0)+solve(h1-h2,w2,0,0));
        }
        else{
            ret=min(ret,solve(h1,i,h2,i-k)+solve(h1-h2,w1-i,0,0));
        }
    }
    swap(h1,w1);
    swap(h2,w2);
    k=w1-w2;
    for(int i=1;i<w1;i++){
        if(i<k){
            ret=min(ret,solve(h1,i,0,0)+solve(h1,w1-i,h2,w2));
        }
        else if(i==k){
            ret=min(ret,solve(h1,k,0,0)+solve(h1-h2,w2,0,0));
        }
        else{
            ret=min(ret,solve(h1,i,h2,i-k)+solve(h1-h2,w1-i,0,0));
        }
    }
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    int h1,w1,h2,w2;
    scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
    printf("%d\n",solve(h1,w1,h2,w2));
    return 0;
}
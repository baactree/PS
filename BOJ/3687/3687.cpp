#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
int p[10]={6,2,5,5,4,5,6,3,7,6};
ll cache[105][100];
ll solve(int idx,int cnt,int last){
    if(idx<0)
        return 0x3f3f3f3f3f3f3f3f;
    if(idx==0){
        if(last!=0)
            return 0;
        return 0x3f3f3f3f3f3f3f3f;
    }
    ll &ret=cache[idx][cnt];
    if(ret!=-1)
        return ret;
    ll r=1;
    for(int i=0;i<min(cnt,16);i++)
        r*=10;
    ret=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<10;i++){
        ret=min(ret,solve(idx-p[i],cnt+1,i)+r*i);
    }
    return ret;
}
int main(){
    int testcase;
    memset(cache,-1,sizeof(cache));
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&n);
        printf("%lld ",solve(n,0,0));
        if(n&1){
            n-=3;
            printf("7");
        }
        while(n){
            printf("1");
            n-=2;
        }
        printf("\n");
    }
    return 0;
}
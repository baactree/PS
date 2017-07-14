#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;

bool prime[10005];
bool check[10005];
bool possi(int x){
    memset(check,0,sizeof(check));
    while(x!=1){
        if(check[x])
            return false;
        check[x]=true;
        int next=0;
        while(x){
            int p=x%10;
            next+=p*p;
            x/=10;
        }
        x=next;
    }
    return true;
}
int main(){
    prime[1]=true;
    for(int i=2;i<10005;i++){
        if(!prime[i]){
            for(int j=i+i;j<10005;j+=i)
                prime[j]=true;
        }
    }
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        int tc,n;
        scanf("%d%d",&tc,&n);
        printf("%d %d %s\n",tc,n,(!prime[n]&&possi(n))?"YES":"NO");
    }
    return 0;
}
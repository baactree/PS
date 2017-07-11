#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    scanf("%d%d",&n,&k);
    if(k==n-1){
        printf("2\n");
        for(int i=2;i<=n;i++)
            printf("1 %d\n",i);
    }
    else if(k==n-2){
        printf("3\n");
        printf("1 2\n");
        printf("1 3\n");
        for(int i=4;i<=n;i++)
            printf("3 %d\n",i);
    }
    else if(n-k-1<=k){
        printf("4\n");
        int t=n-k-1;
        int idx=2;
        int p=k-t;
        for(int i=0;i<t;i++){
            printf("%d %d\n",1,idx);
            printf("%d %d\n",idx,idx+1);
            idx+=2;
        }
        int q=idx-2;
        while(p--){
            printf("%d %d\n",q,idx);
            idx++;
        }
    }
    else{
        int p=(n-1)/k;
        int q=(n-1)%k;
        if(q==0)
            printf("%d\n",p*2);
        else if(q==1)
            printf("%d\n",p*2+1);
        else
            printf("%d\n",p*2+2);
        vector<int> par(k,1);
        n--;
        int idx=2;
        while(n){
            for(int i=0;i<k&&n;i++){
                printf("%d %d\n",par[i],idx);
                par[i]=idx;
                idx++;
                n--;
            }
        }
    }
    return 0;
}
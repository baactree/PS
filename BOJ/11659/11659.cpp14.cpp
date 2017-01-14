#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int sum[100001];
int N,M;
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        int in;
        scanf("%d",&in);
        sum[i]=sum[i-1]+in;
    }
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
            swap(a,b);
        printf("%d\n",sum[b]-sum[a-1]);
    }
    return 0;
}
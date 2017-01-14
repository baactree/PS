#include "bits/stdc++.h"
using namespace std;
int arr[1000000];
int main(){
    int idx=0;
    for(int i=1;i<=100;i++){
        for(int j=0;j<i;j++)
            arr[idx++]=i;
    }
    int sum=0;
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=a-1;i<b;i++)
        sum+=arr[i];
    printf("%d\n",sum);
    return 0;
}
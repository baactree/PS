#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000];
int main(){
    scanf("%d",&n);
    long long sum=0;
    int max_value=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
        max_value=max(max_value,arr[i]);
    }
    if(n==1)
        printf("0\n");
    else if(n==2)
        printf("%lld\n",sum);
    else{
        printf("%lld\n",sum+max_value*(n-2));
    }
    return 0;
}
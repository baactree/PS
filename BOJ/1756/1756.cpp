#include <bits/stdc++.h>
using namespace std;
int d,n;
int arr[300000];
int main(){
    scanf("%d%d",&d,&n);
    for(int i=0;i<d;i++){
        scanf("%d",&arr[i]);
        if(i!=0&&arr[i-1]<arr[i])
            arr[i]=arr[i-1];
    }
    reverse(arr,arr+d);
    int ans=0;
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        int idx=upper_bound(arr+ans,arr+d,in-1)-arr;
        ans=idx+1;
    }
    ans=d-ans+1;
    printf("%d\n",max(0,ans));
    return 0;
}
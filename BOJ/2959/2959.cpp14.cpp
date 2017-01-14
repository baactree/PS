#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[4];
    for(int i=0;i<4;i++)
        scanf("%d",&arr[i]);
    int ans=0;
    ans=max(min(arr[0],arr[1])*min(arr[2],arr[3]),ans);
    ans=max(min(arr[0],arr[2])*min(arr[1],arr[3]),ans);
    ans=max(min(arr[0],arr[3])*min(arr[2],arr[1]),ans);
    printf("%d\n",ans);
    return 0;
}
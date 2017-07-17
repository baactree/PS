#include <bits/stdc++.h>
using namespace std;
int n;
pair<int,int> arr[105];
int main(){
    scanf("%d",&n);
    int fi=0;
    for(int i=0;i<n;i++)
        scanf("%d%d",&arr[i].first,&arr[i].second);
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        fi=max(arr[i].first+arr[i].second,fi+arr[i].second);
    printf("%d\n",fi);
    return 0;
}
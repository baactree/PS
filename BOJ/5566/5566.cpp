#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[1001];
int d[1000];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i+1]);
    for(int i=0;i<m;i++)
        scanf("%d",&d[i]);
    int now=1;
    for(int i=0;i<m;i++){
        now+=d[i];
        now+=arr[now];
        if(now>=n){
            printf("%d\n",i+1);
            return 0;
        }
    }
    return 0;
}
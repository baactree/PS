#include <bits/stdc++.h>
using namespace std;
int n,l;
int arr[1000];
int main(){
    int fi=-1;
    scanf("%d%d",&n,&l);
    l*=2;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        arr[i]*=2;
    }
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(fi>=arr[i]+1)
            continue;
        fi=max(fi+l,arr[i]-1+l);
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
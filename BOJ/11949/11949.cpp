#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[100];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j+1<n;j++){
            if(arr[j]%i>arr[j+1]%i){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[50];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    if(n==1){
        printf("A\n");
        return 0;
    }
    if(n==2){
        if(arr[0]==arr[1]){
            printf("%d\n",arr[0]);
        }
        else{
            printf("A\n");
        }
        return 0;
    }
    int a,b;
    a=b=0;
    if(arr[0]==arr[1]){
        if(arr[1]==arr[2]){
            a=1;
            b=0;
        }
        else{
            printf("B\n");
            return 0;
        }
    }
    else{
        if((arr[2]-arr[1])%(arr[1]-arr[0])==0){
            a=(arr[2]-arr[1])/(arr[1]-arr[0]);
            b=arr[1]-arr[0]*a;
        }
        else{
            printf("B\n");
            return 0;
        }
    }
    for(int i=1;i+2<n;i++){
        int na,nb;
        na=nb=0;
        if(arr[i]==arr[i+1]){
            if(arr[i+1]==arr[i+2]){
                na=1;
                nb=0;
            }
            else{
                printf("B\n");
                return 0;
            }
            continue;
        }
        else{
            if((arr[i+2]-arr[i+1])%(arr[i+1]-arr[i])==0){
                na=(arr[i+2]-arr[i+1])/(arr[i+1]-arr[i]);
                nb=arr[i+1]-arr[i]*na;
            }
            else{
                printf("B\n");
                return 0;
            }
        }
        if(na!=a||nb!=b){
            printf("B\n");
            return 0;
        }
    }
    printf("%d\n",arr[n-1]*a+b);
    return 0;
}
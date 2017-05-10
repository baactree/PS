#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int a,b,c,d;
int p,m,n;
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    scanf("%d%d%d",&p,&m,&n);
    int now=1;
    while(now<1000){
        for(int i=0;i<a;i++)
            arr[now++]++;
        for(int j=0;j<b;j++)
            now++;
    }
    now=1;
    while(now<1000){
        for(int i=0;i<c;i++)
            arr[now++]++;
        for(int i=0;i<d;i++)
            now++;
    }
    printf("%d\n%d\n%d\n",arr[p],arr[m],arr[n]);
    return 0;
}
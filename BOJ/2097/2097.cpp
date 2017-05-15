#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int k;
    for(k=1;k*k<=n;k++);
    k--;
    int h,w;
    h=w=k-1;
    n-=k*k;
    if(n==0){}
    else if(n>k){
        h++;
        w++;
    }
    else{
        h++;
    }
    h=max(1,h);
    w=max(1,w);
    printf("%d\n",h*2+w*2);
    return 0;
}
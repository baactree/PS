#include <bits/stdc++.h>
using namespace std;
int r,c;
int main(){
    scanf("%d%d",&r,&c);
    int n=r*c/2;
    if(n==1){
        printf("1 1\n");
        return 0;
    }
    printf("%d %d\n",n,2*n-1);
    return 0;
}
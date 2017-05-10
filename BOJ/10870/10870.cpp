#include <iostream>
#include <stdio.h>
using namespace std;
int f(int n){
    //기저 사례
    if(n==0||n==1)
        return n;
    //f(n)=f(n-1)+f(n-2)
    return f(n-1)+f(n-2);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    return 0;
}
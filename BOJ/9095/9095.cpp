#include <iostream>
#include <stdio.h>
using namespace std;
int f(int n){
    //기저 사례 n이 0보다 작으면 불가능
    if(n<0)
        return 0;
    //기저 사례 n이 0이면 1
    if(n==0)
        return 1;
    //f(n) = f(n-3) + f(n-2) + f(n-1)
    return f(n-3)+f(n-2)+f(n-1);
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        int n;
        scanf("%d",&n);
        printf("%d\n",f(n));
    }
    return 0;
}
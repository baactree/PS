#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a+b>=2*c)
        printf("%d\n",a+b-2*c);
    else
        printf("%d\n",a+b);
    return 0;
}
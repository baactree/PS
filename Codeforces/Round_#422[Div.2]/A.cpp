#include <bits/stdc++.h>
using namespace std;
int f(int a){
    if(a==0)
        return 1;
    return a*f(a-1);
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    a=min(a,b);
    printf("%d\n",f(a));
    return 0;
}
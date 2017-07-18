#include <bits/stdc++.h>
using namespace std;
int a,b,d;
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        scanf("%d%d%d",&a,&b,&d);
        int c=a-b;
        d-=a;
        printf("Case #%d\n%d\n",tc,(d+c-1)/c+1);
    }
    return 0;
}
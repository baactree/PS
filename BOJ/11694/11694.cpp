#include <bits/stdc++.h>
using namespace std;
int cnt,n,x;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        x^=in;
        if(in>1)
            cnt++;
    }
    if(cnt)
        printf("%s\n",x?"koosaga":"cubelover");
    else
        printf("%s\n",x?"cubelover":"koosaga");
    return 0;
}
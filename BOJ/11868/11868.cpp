#include <bits/stdc++.h>
using namespace std;
int n;
int x;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        x^=in;
    }
    printf("%s\n",x?"koosaga":"cubelover");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    bool flag=false;
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int in;
        scanf("%d",&in);
        if(in==i+1)
            flag=true;
    }
    printf("%d\n",flag?-1:1000000007);
    return 0;
}
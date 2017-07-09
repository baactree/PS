#include <bits/stdc++.h>
using namespace std;
int n,l,d;
bool arr[2000000];
int main(){
    scanf("%d%d%d",&n,&l,&d);
    int st=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++)
            arr[st++]=true;
        st+=5;
    }
    st=0;
    while(true){
        if(!arr[st]){
            printf("%d\n",st);
            return 0;
        }
        st+=d;
    }
    return 0;
}
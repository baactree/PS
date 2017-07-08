#include <bits/stdc++.h>
using namespace std;
int h,m;
bool r[200];
int calc(int a,int b){
    b-=a;
    if(b<0)
        b+=60;
    if(b>=30)
        b=60-b;
    return b*6;
}
int main(){
    for(int i=1;i<=720;i++){
        r[calc(h,m)]=true;
        m=(m+1)%60;
        if(i%12==0)
            h=(h+1)%60;
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%s\n",r[n]?"Y":"N");
    }
    return 0;
}
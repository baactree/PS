#include <bits/stdc++.h>
using namespace std;
int n;
char str[1000005];
bool possi(int x,int u,int v){
    if(x==0)
        return true;
    if(u==0){
        if(v==1){
            // a->b
            if(str[x-1]=='A')
                return possi(x-1,0,2);
            if(str[x-1]=='B')
                return possi(x-1,2,1);
            return false;
        }
        //a->c
        if(str[x-1]=='A')
            return possi(x-1,0,2);
        if(str[x-1]=='B')
            return possi(x-1,2,0);
        return possi(x-1,0,2);
        
    }
    if(u==1){
        if(v==2){
            //b->c
            if(str[x-1]=='A')
                return false;
            if(str[x-1]=='B')
                return possi(x-1,1,0);
            return possi(x-1,0,2);
        }
        //b->a
        if(str[x-1]=='A')
            return possi(x-1,1,0);
        if(str[x-1]=='B')
            return possi(x-1,1,0);
        return possi(x-1,0,1);
    }
    if(v==0){
        //c->a
        if(str[x-1]=='A')
            return possi(x-1,1,0);
        if(str[x-1]=='B')
            return false;
        return possi(x-1,2,1);
    }
    //c->b
    if(str[x-1]=='A')
        return possi(x-1,1,2);
    if(str[x-1]=='B')
        return possi(x-1,2,1);
    return possi(x-1,2,1); 
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        scanf("%d%s",&n,str);
        printf("Case #%d\n",tc);
        printf("%s\n",possi(n,0,1)?"YES":"NO");
    }
    return 0;
}
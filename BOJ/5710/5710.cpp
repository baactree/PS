#include <bits/stdc++.h>
using namespace std;
int calc(int x){
    int ret=0;
    if(x>1e6){
        ret+=(x-1e6)*7;
        x=1e6;
    }
    if(x>1e4){
        ret+=(x-1e4)*5;
        x=1e4;
    }
    if(x>1e2){
        ret+=(x-1e2)*3;
        x=1e2;

    }
    ret+=x*2;
    return ret;
}
int icalc(int x){
    int ret=0;
    if(x<=100*2){
        ret+=x/2;
        return ret;
    }
    ret+=100;
    x-=200;
    if(x<=9900*3){
        ret+=x/3;
        return ret;
    }
    ret+=9900;
    x-=9900*3;
    if(x<=(1e6-1e4)*5){
        ret+=x/5;
        return ret;
    }
    ret+=1e6-1e4;
    x-=(1e6-1e4)*5;
    ret+=x/7;
    return ret;
}
int a,b;
int main(){
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a==0&&b==0)
            break;
        int xy=icalc(a);
        int le,ri,mid,x;
        le=0;
        ri=xy/2;
        x=-1;
        while(le<=ri){
            mid=(le+ri)/2;
            if(calc(xy-mid)-calc(mid)>=b){
                x=mid;
                le=mid+1;
            }
            else
                ri=mid-1;
        }
        printf("%d\n",calc(x));
    }
    return 0;
}
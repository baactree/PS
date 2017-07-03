#include <bits/stdc++.h>
using namespace std;
double a,b,c;
int st[5]={1000,1500,2000,2500,3000};
int fi[5]={1500,2000,2500,3000,3500};
double cache[20][4000];
int le,ri;
double solve(int idx,int score){
    if(idx==20){
        if(score>=le&&score<ri)
            return 1;
        return 0;
    }
    double &ret=cache[idx][score];
    if(ret>-0.5)
        return ret;
    ret=solve(idx+1,score+50)*a;
    ret+=solve(idx+1,score-50)*b;
    ret+=solve(idx+1,score)*c;
    return ret;
}
int main(){
    scanf("%lf%lf%lf",&a,&b,&c);
    for(int i=0;i<5;i++){
        le=st[i];
        ri=fi[i];
        for(int j=0;j<20;j++)
            for(int k=0;k<4000;k++)
                cache[j][k]=-1.0;
        printf("%.8lf\n",solve(0,2000));
    }
    return 0;
}
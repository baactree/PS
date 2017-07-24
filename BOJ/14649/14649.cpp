#include <bits/stdc++.h>
using namespace std;
int cnt[105];
int p,n;
int ans[3];
void paint(int x,int mode){
    if(mode){
        for(int i=x+1;i<=100;i++)
            cnt[i]++;
    }
    else{
        for(int i=x-1;i>=1;i--)
            cnt[i]++;
    }
}
int main(){
    scanf("%d%d",&p,&n);
    for(int i=0;i<n;i++){
        int x;
        char in[2];
        scanf("%d%s",&x,in);
        paint(x,in[0]=='R');
    }
    for(int i=1;i<=100;i++)
        ans[cnt[i]%3]++;
    printf("%.2lf %.2lf %.2lf\n",p/100.*ans[0],p/100.*ans[1],p/100.*ans[2]);
    return 0;
}
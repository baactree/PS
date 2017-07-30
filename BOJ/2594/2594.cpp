#include <bits/stdc++.h>
using namespace std;
int t[1500];
int n;
void paint(int st,int fi){
    for(int i=st;i<fi;i++)
        t[i]++;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        paint(x/100*60+x%100-10,y/100*60+y%100+10);
    }
    int ans=0;
    int cnt=0;
    for(int i=600;i<1320;i++){
        if(t[i])
            cnt=0;
        else
            cnt++;
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}
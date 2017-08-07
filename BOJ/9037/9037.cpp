#include <bits/stdc++.h>
using namespace std;
int n;
int now[10];
int there[10];
bool possi(){
    int x=now[0];
    for(int i=0;i<n;i++)
        if(x!=now[i])
            return false;
    return true;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&now[i]);
            if(now[i]&1)
                now[i]++;
        }
        int ans=0;
        while(true){
            if(possi())
                break;
            for(int i=0;i<n;i++){
                there[(i+1)%n]=now[i]/2;
                now[i]/=2;
            }
            for(int i=0;i<n;i++){
                now[i]+=there[i];
                there[i]=0;
                if(now[i]&1)
                    now[i]++;
            }
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
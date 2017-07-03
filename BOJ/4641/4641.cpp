#include <bits/stdc++.h>
using namespace std;
int main(){
    int in;
    while(true){
        scanf("%d",&in);
        if(in==-1)
        break;
        map<int,int> mp;
        mp[in]++;
        while(true){
            scanf("%d",&in);
            if(in==0)
            break;
            mp[in]++;
        }
        int ans=0;
        for(map<int,int>::iterator it =mp.begin();it!=mp.end();it++){
            ans+=mp[it->first*2];
        }        
        printf("%d\n",ans);
    }
    return 0;
}
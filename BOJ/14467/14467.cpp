#include <bits/stdc++.h>
using namespace std;
int n;
int loc[105];
int main(){
    memset(loc,-1,sizeof(loc));
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(loc[a]==-1){
            loc[a]=b;
        }
        else{
            if(loc[a]!=b){
                ans++;
                loc[a]=b;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
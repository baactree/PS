#include <bits/stdc++.h>
using namespace std;
int n;
set<int> s;
int main(){
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        int x;
        scanf("%d",&x);
        if(!s.insert(x).second)
            s.erase(x);
        ans=max(ans,(int)s.size());
    }
    printf("%d\n",ans);
    return 0;
}
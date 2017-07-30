#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        vector<ll> vec;
        int budget=5e6;
        while(true){
            int in;
            scanf("%d",&in);
            if(in==0)
                break;
            vec.push_back(in);
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            ll now=2;
            for(int j=0;j<=i;j++){
                now*=vec[i];
                if(now>budget)
                    goto next;
            }
            budget-=now;
        }
        printf("%d\n",(int)(5e6-budget));
        continue;
        next:
        printf("Too expensive\n");
    }
    return 0;
}
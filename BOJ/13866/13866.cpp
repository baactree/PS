#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec;
    for(int i=0;i<4;i++){
        int in;
        scanf("%d",&in);
        vec.push_back(in);
    }
    sort(vec.begin(),vec.end());
    int ans=0x3f3f3f3f;
    do{
        ans=min(ans,abs(vec[0]+vec[1]-vec[2]-vec[3]));
    }while(next_permutation(vec.begin(),vec.end()));
    printf("%d\n",ans);
    return 0;
}
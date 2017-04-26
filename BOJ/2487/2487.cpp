#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int arr[20001];
bool trip[20001];
vector<int> cycle;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int dfs(int now,int st){
    trip[now]=true;
    int ret=1;
    int there=arr[now];
    if(!trip[there]&&there!=st)
        ret+=dfs(there,st);
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++){
        if(!trip[i])
            cycle.push_back(dfs(i,i));
    }
    sort(cycle.begin(),cycle.end());
    cycle.erase(unique(cycle.begin(),cycle.end()),cycle.end());
    int pre=cycle[0];
    for(int i=1;i<cycle.size();i++){
        int g=gcd(pre,cycle[i]);
        pre=pre/g*cycle[i];
    }
    printf("%d\n",pre);
    return 0;
}
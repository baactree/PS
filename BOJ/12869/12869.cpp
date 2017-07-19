#include <bits/stdc++.h>
using namespace std;
int n;
int cache[65][65][65];
int solve(int a,int b,int c){
    a=max(0,a);
    b=max(0,b);
    c=max(0,c);
    if(a==0&&b==0&&c==0)
        return 0;
    int &ret=cache[a][b][c];
    if(ret!=-1)
        return ret;
    vector<int> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    sort(vec.begin(),vec.end());
    ret=0x3f3f3f3f;
    do{
        ret=min(ret,solve(vec[0]-9,vec[1]-3,vec[2]-1)+1);
    }while(next_permutation(vec.begin(),vec.end()));
    return ret;
}
int arr[3];
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",solve(arr[0],arr[1],arr[2]));
    return 0;
}
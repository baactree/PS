#include <bits/stdc++.h>
using namespace std;
int cache[5001][5001];
int N;
int arr[5000];
int solve(int left,int right,int remain){
    if(remain==0||remain==1)
        return 0;
    int &ret=cache[left][right];
    if(ret!=-1)
        return ret;
    ret=0x3f3f3f3f;
    if(arr[left]==arr[right])
        ret=min(ret,solve(left+1,right-1,remain-2));
    ret=min(ret,solve(left+1,right,remain-1)+1);
    ret=min(ret,solve(left,right-1,remain-1)+1);
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    printf("%d\n",solve(0,N-1,N));
    return 0;
}


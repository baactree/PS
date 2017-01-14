#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[301][20];
int cache[301][20];
int solve(int money,int idx){
    if(idx==M)
        return 0;
    int &ret=cache[money][idx];
    if(ret!=-1)
        return ret;
    for(int i=money;i>=0;i--)
        ret=max(ret,solve(money-i,idx+1)+arr[i][idx]);
    return ret;
}
void get_solve(int money,int idx){
    if(idx==M)
        return;
    int nmoney=-1;
    int nprofit=-1;
    for(int i=money;i>=0;i--){
        int temp=solve(money-i,idx+1)+arr[i][idx];
        if(temp>nprofit){
            nprofit=temp;
            nmoney=i;
        }
    }
    printf("%d ",nmoney);
    get_solve(money-nmoney,idx+1);
}
int main(){
    memset(cache,-1,sizeof(cache));
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        int temp;
        scanf("%d",&temp);
        for(int j=0;j<M;j++)
            scanf("%d",&arr[temp][j]);
    }
    printf("%d\n",solve(N,0));
    get_solve(N,0);
    return 0;
}

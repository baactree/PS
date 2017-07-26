#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[1005];
//해당 정점의 컴포넌트 번호
int comp[1005];
//해당 컴포넌트의 사이즈
int comp_size[1005];
//해당 컴포넌트에 포함된 사이클의 크기
int comp_cycle[1005];
//해당 정점의 방문 여부
bool trip[1005];
//사이클 크기 세는거, 컴포넌트 번호
int cnt,comp_num;
int dfs(int now,int num){
    int ret=num;
    trip[now]=true;
    int there=arr[now];
    if(trip[there]){
        if(comp[there]==-1){
            for(int temp=there;temp!=now;temp=arr[temp])
                cnt++;
            cnt++;
        }
        else
            ret=min(ret,comp[there]);
    }
    else
        ret=min(ret,dfs(there,num));
    comp[now]=ret;
    comp_size[ret]++;
    return ret;
}
int cache[1005][1005];
const int inf=0x3f3f3f3f;
int solve(int idx,int f){
    if(f>k)
        return -inf;
    if(idx==comp_num)
        return f;
    int &ret=cache[idx][f];
    if(ret!=-1)
        return ret;
    ret=solve(idx+1,f);
    for(int i=comp_cycle[idx];i<=comp_size[idx];i++)
        ret=max(ret,solve(idx+1,f+i));
    return ret;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    memset(comp,-1,sizeof(comp));
    for(int i=1;i<=n;i++){
        if(!trip[i]){
            cnt=0;
            int temp=dfs(i,comp_num);
            comp_cycle[temp]=max(comp_cycle[temp],cnt);
            if(temp==comp_num)
                comp_num++;
        }
    }
    memset(cache,-1,sizeof(cache));
    printf("%d\n",solve(0,0));
    return 0;
}
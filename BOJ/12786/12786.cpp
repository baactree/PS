#include <bits/stdc++.h>
using namespace std;
int n,k;
int mat[101][22];
bool trip[101][22][55];
struct Node{
    int idx,h,t;
};
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int in;
        scanf("%d",&in);
        for(int j=0;j<in;j++){
            int o;
            scanf("%d",&o);
            mat[i][o]=true;
        }
    }
    mat[0][1]=true;
    queue<Node> q;
    q.push({0,1,0});
    while(!q.empty()){
        int idx=q.front().idx;
        int h=q.front().h;
        int t=q.front().t;
        q.pop();
        if(idx==n)
            continue;
        if(mat[idx+1][h]){
            if(!trip[idx+1][h][t]){
                trip[idx+1][h][t]=true;
                q.push({idx+1,h,t});
            }
        }
        if(h+1<=20&&mat[idx+1][h+1]){
            if(!trip[idx+1][h+1][t]){
                trip[idx+1][h+1][t]=true;
                q.push({idx+1,h+1,t});
            }
        }
        if(mat[idx+1][min(20,h*2)]){
            if(!trip[idx+1][min(20,h*2)][t]){
                trip[idx+1][min(20,h*2)][t]=true;
                q.push({idx+1,min(20,h*2),t});
            }
        }
        if(h-1>=0&&mat[idx+1][h-1]){
            if(!trip[idx+1][h-1][t]){
                trip[idx+1][h-1][t]=true;
                q.push({idx+1,h-1,t});
            }
        }
        if(t<k){
            for(int i=1;i<=20;i++){
                if(mat[idx+1][i]){
                    if(!trip[idx+1][i][t+1]){
                        trip[idx+1][i][t+1]=true;
                        q.push({idx+1,i,t+1});
                    }
                }
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=20;i++)
        for(int j=0;j<=k;j++)
            if(trip[n][i][j])
                ans=min(ans,j);
    printf("%d\n",ans==0x3f3f3f3f?-1:ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,m;
int mat[105][105];
bool trip[105];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d",&m);
        while(m--){
            int x;
            scanf("%d",&x);
            mat[i][x]=true;
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mat[i][j]|=(mat[i][k]&&mat[k][j]);
    bool ans=false;
    queue<int> q;
    q.push(1);
    trip[1]=true;
    while(!q.empty()){
        int now=q.front();
        if(mat[now][now])
            ans=true;
        q.pop();
        for(int there=1;there<=n;there++)
            if(mat[now][there]&&!trip[there]){
                trip[there]=true;
                q.push(there);
            }
    }
    printf("%s\n",ans?"CYCLE":"NO CYCLE");
    return 0;
}
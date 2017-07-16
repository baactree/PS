#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[201];
//0이 간선임
bool mat[201][201];
int matcheda[201];
int matchedb[201];
bool trip[201];
bool dfs(int now){
    if(trip[now])
        return false;
    trip[now]=true;
    for(int i=1;i<=n;i++)
        if(!mat[now][i]){
            if(matchedb[i]==-1||dfs(matchedb[i])){
                matchedb[i]=now;
                matcheda[now]=i;
                return true;
            }
        }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a==1){
            for(int i=b;i<=c;i++)
                for(int j=d+1;j<=n;j++)
                    mat[i][j]=1;
            for(int i=1;i<b;i++)
                mat[i][d]=1;
            for(int i=c+1;i<=n;i++)
                mat[i][d]=1;
        }
        else{
            for(int i=b;i<=c;i++)
                for(int j=1;j<d;j++)
                    mat[i][j]=1;
            for(int i=1;i<b;i++)
                mat[i][d]=1;
            for(int i=c+1;i<=n;i++)
                mat[i][d]=1;
        }
    }
    
    memset(matcheda,-1,sizeof(matcheda));
    memset(matchedb,-1,sizeof(matchedb));
    int cnt=0;
    for(int i=1;i<=n;i++){
        memset(trip,0,sizeof(trip));
        if(dfs(i))
            cnt++;
    }
    if(cnt!=n){
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",matcheda[i]);
    return 0;
}
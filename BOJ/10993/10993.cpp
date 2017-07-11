#include <bits/stdc++.h>
using namespace std;
int n;
int dx[15];
int dy[15];
bool mat[3000][3000];
void solve(int x,int y,int k){
    if(k==1){
        mat[x][y]=true;
        return;
    }
    if(k&1){
        int sy=y-dy[k]/2;
        for(int i=0,j=0;i<dy[k];i++){
            mat[x+dx[k]-1][sy+i]=true;
            mat[x+dx[k]-1-j][sy+i]=true;
            if(i<dy[k]/2)
                j++;
            else
                j--;
        }
        solve(x+dx[k]-2,y,k-1);
        return;
    }
    int sy=y-dy[k]/2;
    for(int i=0,j=0;i<dy[k];i++){
        mat[x-dx[k]+1][sy+i]=true;
        mat[x-dx[k]+1-j][sy+i]=true;
        if(i<dy[k]/2)
            j--;
        else
            j++;
    }
    solve(x-dx[k]+2,y,k-1);
}
int main(){
    dx[1]=1;
    dy[1]=1;
    for(int i=2;i<15;i++){
        dx[i]=dx[i-1]*2+1;
        dy[i]=dy[i-1]*2+3;
    }
    scanf("%d",&n);
    if(n&1){
        solve(0,dy[n]/2,n);
    }
    else{
        solve(dx[n]-1,dy[n]/2,n);
    }
    for(int i=0;i<dx[n];i++){
        string ans="";
        bool flag=false;
        for(int j=dy[n]-1;j>=0;j--){
            if(mat[i][j]){
                flag=true;
                ans+="*";
            }
            if(!flag)
                continue;
            if(!mat[i][j])
                ans+=" ";
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
    }
    return 0;
}
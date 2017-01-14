#include "bits/stdc++.h"
using namespace std;
int N,M;
bool mat[3*(1<<10)][(1<<10)*6-1];
void solve(int x,int y,int k){
    if(k==3){
        mat[x][y]=true;
        mat[x+1][y-1]=true;
        mat[x+1][y+1]=true;
        mat[x+2][y-2]=true;
        mat[x+2][y-1]=true;
        mat[x+2][y]=true;
        mat[x+2][y+1]=true;
        mat[x+2][y+2]=true;
        return;
    }
    k/=2;
    solve(x,y,k);
    solve(x+k,y-k,k);
    solve(x+k,y+k,k);
    return;
}
int main(){
    scanf("%d",&N);
    M=N*2-1;
    solve(0,M/2,N);
    for(int i=0;i<N;i++){
        string ans="";
        for(int j=0;j<M;j++){
            if(mat[i][j])
                ans+="*";
            else
                ans+=" ";
        }
        puts(ans.c_str());
    }
    return 0;
}
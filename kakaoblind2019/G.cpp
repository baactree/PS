#include <bits/stdc++.h>

using namespace std;
int n;
int dx[2][6]={
    {0,0,0,1,1,1},
    {0,0,1,1,2,2}
};
int dy[2][6]={
    {0,1,2,0,1,2},
    {0,1,0,1,0,1}
};
bool safe(int x,int y){
    return min(x,y)>=0&&max(x,y)<n;
}
bool possi(int x,int y,int k,vector<vector<int> > &cnt,vector<vector<int> > &mat,vector<vector<int> > &chk){
    int col=-1;
    int cur=0;
    for(int i=0;i<6;i++){
        int nx=x+dx[k][i];
        int ny=y+dy[k][i];
        if(safe(nx,ny)){
            if(mat[nx][ny]){
                if(col==-1)col=mat[nx][ny];
                else{
                    if(col!=mat[nx][ny])return false;
                }
            }
            else{
                cur++;  
                if(cnt[nx][ny])return false;
            } 
        }
        else return false;
    }
    if(cur!=2)return false;
    for(int i=0;i<6;i++){
        int nx=x+dx[k][i];
        int ny=y+dy[k][i];
        chk[nx][ny]=true;
    }
    return true;
}
int solution(vector<vector<int> > mat) {
    n=mat.size();
    int answer = 0;
    vector<vector<int> > cnt(n,vector<int>(n)),chk(n,vector<int>(n));
    while(true){
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cnt[i][j]=chk[i][j]=0;
        bool flag=false;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cnt[i][j]=(mat[i][j]>0);
        for(int i=1;i<n;i++)for(int j=0;j<n;j++)cnt[i][j]+=cnt[i-1][j];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<2;k++)
                    if(possi(i,j,k,cnt,mat,chk)){
                        flag=true;
                        answer++;
                    }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(chk[i][j])mat[i][j]=0;
        if(!flag)break;
    }
    return answer;
}
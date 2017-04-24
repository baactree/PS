#include <bits/stdc++.h>
using namespace std;
char mat[10][11];
bool now[10][10];
char pick[10];
int n,m;
bool flag;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void solve(int idx){
    if(flag){
        return ;
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(now[i][j])
                cnt++;
    if(cnt==0){
        flag=true;
        for(int i=0;i<idx;i++)
            printf("%c",pick[i]);
        return;
    }
    //위로

    //아래로
    //오른쪽
    //왼쪽
}
int main(){
    int TestCase;
    scanf("%d",&TestCase);
    while(TestCase--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",mat[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]=='.')
                    now[i][j]=true;
        flag=false;
        solve(0);
        if(!flag){
            printf("XHAE\n");
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int mat[3][3];
bool possi(int now){
    for(int i=0;i<3;i++){
        if(mat[i][0]==now&&mat[i][1]==now&&mat[i][2]==now) return true;
        if(mat[0][i]==now&&mat[1][i]==now&&mat[2][i]==now)  return true;
    }
    if(mat[0][0]==now&&mat[1][1]==now&&mat[2][2]==now) return true;
    if(mat[0][2]==now&&mat[1][1]==now&&mat[2][0]==now) return true;
    return false;
}
int main(){
    int st;
    memset(mat,-1,sizeof(mat));
    scanf("%d",&st);
    st--;
    int cnt=0;
    while(true){
        int x,y;
        scanf("%d%d",&x,&y);
        cnt++;
        x--;y--;
        mat[x][y]=st;
        if(possi(st)) break;
        if(cnt==9){
            printf("0\n");
            return 0;
        }
        st=1-st;
    }
    printf("%d\n",st+1);
    return 0;
}
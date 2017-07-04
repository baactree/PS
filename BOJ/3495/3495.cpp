#include <bits/stdc++.h>
using namespace std;
int h,w;
char mat[105][105];
int main(){
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++)
        scanf("%s",mat[i]);
    int ans=0;
    for(int i=0;i<h;i++){
        bool flag=false;
        for(int j=0;j<w;j++){
            if(!flag&&(mat[i][j]=='\\'||mat[i][j]=='/')){
                ans++;
                flag=true;
            }
            else if(flag&&(mat[i][j]=='\\'||mat[i][j]=='/')){
                flag=false;
            }
            else if(flag&&mat[i][j]=='.')
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
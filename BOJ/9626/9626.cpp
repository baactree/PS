#include <bits/stdc++.h>
using namespace std;
int n,m;
int u,l,r,d;
char mat[10][15];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&u,&l,&r,&d);
    for(int i=0;i<n;i++)
        scanf("%s",mat[i]);
    for(int i=0;i<n+u+d;i++){
        for(int j=0;j<m+l+r;j++){
            if(i>=u&&i<u+n&&j>=l&&j<l+m){
                printf("%c",mat[i-u][j-l]);
            }
            else{
                printf("%c",(((i+j)&1)?'.':'#'));
            }
        }
        printf("\n");
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
using namespace std;
int n,m;
int mat[600][600];
int poly[5][4][4]={
    {
        {1,1,1,1},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,0,0},
        {0,0,0,0}
    },
    {
        {1,0,0,0},
        {1,0,0,0},
        {1,1,0,0},
        {0,0,0,0}
    },
    {
        {1,0,0,0},
        {1,1,0,0},
        {0,1,0,0},
        {0,0,0,0}
    },
    {
        {1,1,1,0},
        {0,1,0,0},
        {0,0,0,0},
        {0,0,0,0}
    }
};
bool safe(int x,int y){
    return x>=50&&x<50+n&&y>=50&&y<50+m;
}
void rotate(int x){
    int temp[4][4]={0,};
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            temp[j][3-i]=poly[x][i][j];
        }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            poly[x][i][j]=temp[i][j];
}
void flip(int x,int mode){
    int temp[4][4]={0,};
    if(mode){
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                temp[i][3-j]=poly[x][i][j];
    }
    else{
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                temp[3-i][j]=poly[x][i][j];
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            poly[x][i][j]=temp[i][j];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mat[i+50][j+50]);
    int ans=0;
    for(int i=0;i<5;i++){
        for(int k=0;k<2;k++){
            for(int j=0;j<4;j++){
                for(int x=0;x<600;x++)
                    for(int y=0;y<600;y++){
                        int cnt=0;
                        bool flag=false;
                        for(int q=0;q<4;q++)
                            for(int p=0;p<4;p++){
                                if(poly[i][q][p]==1){
                                    if(safe(x+q,y+p)){
                                        cnt+=mat[x+q][y+p];
                                    }
                                    else{
                                        flag=true;
                                    }
                                }
                            }
                        if(flag)
                            continue;
                        ans=max(cnt,ans);
                    }
                rotate(i);
            }
            flip(i,k);
        }
    }
    printf("%d\n",ans);
    return 0;
}
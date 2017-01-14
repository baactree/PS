#include <stdio.h>
#include<algorithm>
#include<iostream>
#include <string.h>
#include<vector>
using namespace std;
vector <int> v;
bool trip [30][30];
int m[30][30] ;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n;
bool safe(int x,int y){
   return x>=0&&y>=0&&x<n&&y<n; 
}
int dfs(int x,int y){
    trip [x][y] =true;
    int ret = 0;
     
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(safe(nx,ny)&&!trip[nx][ny]&&m[nx][ny]==1){
        ret+=dfs(nx,ny   );
        }
    }
    return ret+1;
     
}
 
int main() {
     
    scanf("%d", &n);
 
     
 
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%1d", &m[i][j]);
        }
    }
     
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!trip[i][j]&&m[i][j]==1){
                v.push_back(dfs(i,j));
            }
        }
    }
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(int i =0;i<v.size();i++){
        printf("%d\n",v[i]);
    }
    return 0;
    }
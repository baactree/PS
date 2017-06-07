// =====================================================================================
// 
//       Filename:  14585.cpp
//        Created:  2017년 06월 07일 17시 22분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================
//
#include <bits/stdc++.h>
using namespace std;
int mat[305][305];
int n,m;
int cache[305][305];
int solve(int x,int y){
    if(x==304&&y==304){
        return 0;
    }
    int &ret=cache[x][y];
    if(ret!=-1)
        return ret;
    int now=0;
    if(mat[x][y])
        now=max(0,m-(x+y));
    if(x!=304)
        ret=max(ret,solve(x+1,y)+now);
    if(y!=304)
        ret=max(ret,solve(x,y+1)+now);
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        mat[x][y]=1;
    }
    memset(cache,-1,sizeof(cache));
    printf("%d\n",solve(0,0));
    return 0;
}

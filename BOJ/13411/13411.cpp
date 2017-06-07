// =====================================================================================
// 
//       Filename:  13411.cpp
//        Created:  2017년 06월 07일 17시 22분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int x,y,v,idx;
    bool operator < (const Node &rhs)const{
        long long a=((long long)x*x+y*y)*(rhs.v*rhs.v);
        long long b=((long long)rhs.x*rhs.x+rhs.y*rhs.y)*(v*v);
        if(a==b)
            return idx<rhs.idx;
        return a<b;
    }
};
Node arr[100000];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].x,&arr[i].y,&arr[i].v);
        arr[i].idx=i;
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
        printf("%d\n",arr[i].idx+1);
    return 0;
}

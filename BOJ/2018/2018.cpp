// =====================================================================================
// 
//       Filename:  2018.cpp
//        Created:  2017년 03월 13일 22시 53분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n,le,ri,sum,ans;

int main(){
    scanf("%d",&n);
    while(ri<n&&le<=ri){
        if(sum==n){
            ans++;
        }
        if(sum<=n){
            sum+=ri;
            ri++;
        }
        else if(sum>n){
            sum-=le;
            le++;
        }
    }
    printf("%d\n",ans+1);
}

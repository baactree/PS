// =====================================================================================
// 
//       Filename:  11880.cpp
//        Created:  2017년 06월 05일 17시 45분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",min((a+b)*(a+b)+c*c,min((a+c)*(a+c)+b*b,(b+c)*(b+c)+a*a)));
    }
    return 0;
}

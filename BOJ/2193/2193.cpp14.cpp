#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
typedef unsigned long long int LLU;
using namespace std;
LLU dp_0[91];//마지막 자리0의 갯수 
LLU dp[91];//마지막 자리 0의 갯수*2+마지막 자리 1의 갯수 
LLU dp_1[91];//마지막 자리1의 갯수 
 
int main()
{
    dp[1]=1;
    dp[2]=1;
    dp_0[2]=1;
    dp_1[2]=0;
    for(int i=3;i<91;i++)
    {
        dp[i]=dp_0[i-1]*2+dp_1[i-1];
        dp_0[i]=dp_0[i-1]+dp_1[i-1];
        dp_1[i]=dp_0[i-1];
    }
    int N;
    cin>>N;
    printf("%llu\n",dp[N]);
    return 0;
}

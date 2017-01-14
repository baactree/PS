#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <cmath>
#include <deque>
using namespace std;
typedef unsigned long long int LLU;
LLU checkFive(LLU num)
{
    // Initialize result
    LLU count = 0;
 
    // Keep dividing n by powers of 5 and update count
    for (LLU i = 5; num / i >= 1; i *= 5)
        count += num / i;
 
    return count;
}
LLU checkTwo(LLU num)
{
    // Initialize result
    LLU count = 0;
 
    // Keep dividing n by powers of 5 and update count
    for (LLU i = 2; num / i >= 1; i *= 2)
        count += num / i;
 
    return count;
}
int main()
{
    LLU n, r;
  scanf("%llu%llu",&n,&r);
    LLU five = 0,two=0;
        five += checkFive(n);
        five -= checkFive(r);
        five -= checkFive(n-r);
        two += checkTwo(n);
        two -= checkTwo(r);
        two -= checkTwo(n - r);
    printf("%llu\n",min(five,two));
//    while(true);
    return 0;
}

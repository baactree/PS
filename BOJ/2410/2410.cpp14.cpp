#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
#define X 1000000000
int N;
int cache[20][1000001];
int search(int idx,int sum){
    if(sum==N)
        return 1;
    if(sum>N)
        return 0;
    if(idx==20)
        return 0;
    int &ret=cache[idx][sum];
    if(ret!=-1)
        return ret;
    ret=(search(idx,sum+pow(2,idx))%X+search(idx+1,sum)%X)%X;
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    cin>>N;
    printf("%d\n",search(0,0));
}
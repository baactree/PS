#include "bits/stdc++.h"
using namespace std;
int cache[500][500];
int len;
string str;
int solve(int left,int right){
    int size=right-left+1;
    if(size<2)
        return 0;
    int &ret=cache[left][right];
    if(ret!=-1)
        return ret;
    ret=0;
    if(str[left]=='a'&&str[right]=='t')
        ret=max(ret,solve(left+1,right-1)+2);
    if(str[left]=='g'&&str[right]=='c')
        ret=max(ret,solve(left+1,right-1)+2);
    for(int i=left;i<right;i++)
        ret=max(ret,solve(left,i)+solve(i+1,right));
    return ret;
}
int main(){
    memset(cache,-1,sizeof(cache));
    cin>>str;
    len=str.size();
    printf("%d\n",solve(0,len-1));
    return 0;
}
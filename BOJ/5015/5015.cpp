#include <bits/stdc++.h>
using namespace std;
int n;
int cache[105][105];
string pattern;
string str;
int solve(int aidx,int bidx){
    if(aidx==pattern.size()){
        return bidx==str.size();
    }
    int &ret=cache[aidx][bidx];
    if(ret!=-1)
        return ret;
    ret=false;
    if(pattern[aidx]=='*'){
        ret|=solve(aidx+1,bidx);
        if(bidx<str.size())
            ret|=solve(aidx,bidx+1);
    }
    else{
        if(bidx<str.size()&&pattern[aidx]==str[bidx])
            ret|=solve(aidx+1,bidx+1);
    }
    return ret;
}
int main(){
    cin>>pattern>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        memset(cache,-1,sizeof(cache));
        if(solve(0,0))
            cout<<str<<'\n';
    }
    return 0;
}
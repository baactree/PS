#include <bits/stdc++.h>
using namespace std;
string str;
int cache[51][51];
int solve(int le,int ri){
    if(le>=ri)
        return 0;
    int &ret=cache[le][ri];
    if(ret!=-1)
        return ret;
    ret=0x3f3f3f3f;
    if(str[le]==str[ri])
        ret=min(ret,solve(le+1,ri-1));
    ret=min(ret,solve(le+1,ri)+1);
    ret=min(ret,solve(le,ri-1)+1);
    ret=min(ret,solve(le+1,ri-1)+1);
    return ret;
}
int calc(){
    int ret=0x3f3f3f3f;
    memset(cache,-1,sizeof(cache));
    for(int i=0;i<str.size();i++)
        for(int j=i;j<str.size();j++)
            ret=min(ret,solve(i,j)+i+((int)str.size()-1-j));
    return ret;
}
int main(){
    cin>>str;
    int ans=calc();
    for(int i=0;i<str.size();i++)
        for(int j=i+1;j<str.size();j++){
            swap(str[i],str[j]);
            ans=min(ans,calc()+1);
            swap(str[i],str[j]);
        }
    printf("%d\n",ans);
    return 0;
}
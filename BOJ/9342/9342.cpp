#include <bits/stdc++.h>
using namespace std;
char t[6]={'A','B','C','D','E','F'};
bool possi(const string &str){
    int idx=0;
    bool flag=false;
    for(int i=1;i<6;i++)
        if(str[idx]==t[i])
            flag=true;
    if(flag)
        idx++;
    int cnt=0;
    while(idx<str.size()&&str[idx]=='A'){
        cnt++;
        idx++;
    }
    if(cnt==0)
        return false;
    cnt=0;
    while(idx<str.size()&&str[idx]=='F'){
        cnt++;
        idx++;
    }
    if(cnt==0)
        return false;
    while(idx<str.size()&&str[idx]=='C'){
        cnt++;
        idx++;
    }
    if(cnt==0)
        return false;
    if(idx<str.size()){
        bool f=false;
        for(int i=0;i<6;i++)
            if(str[idx]==t[i])
                f=true;
        if(f)
            idx++;
    }
    return idx==str.size();
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        string str;
        cin>>str;
        printf("%s\n",possi(str)?"Infected!":"Good");
    }
    return 0;
}
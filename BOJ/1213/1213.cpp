#include <bits/stdc++.h>
using namespace std;
string arr;
int cnt[26];
string solve(){
    for(int i=0;i<arr.size();i++){
        cnt[arr[i]-'A']++;
    }
    int even=0;
    int odd=0;
    for(int i=0;i<26;i++){
        if(cnt[i]&1)
            odd++;
        else
            even++;
    }
    if(arr.size()&1&&odd!=1)
        return "I'm Sorry Hansoo";
    if(!(arr.size()&1)&&odd!=0)
        return "I'm Sorry Hansoo";
    string ret="";

    for(int i=0;i<26;i++){
        while(cnt[i]>1){
            ret+=(char)(i+'A');
            cnt[i]-=2;
        }
    }
    string temp="";
    if(odd==1){
        for(int i=0;i<26;i++)
            if(cnt[i]&1)
                temp=(char)(i+'A');
    }
    string rret=ret;
    reverse(rret.begin(),rret.end());
    return ret+temp+rret;
}
int main(){
    cin>>arr;
    cout<<solve()<<endl;
    return 0;
}

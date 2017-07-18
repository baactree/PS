#include <bits/stdc++.h>
using namespace std;
int cnt[26];
int main(){
    int testcase;
    scanf("%d",&testcase);
    for(int tc=1;tc<=testcase;tc++){
        memset(cnt,0,sizeof(cnt));
        string str;
        cin>>str;
        for(int i=0;i<str.size();i++)
            cnt[str[i]-'a']++;
        printf("Case #%d\n%d\n",tc,min({cnt['h'-'a'],cnt['e'-'a'],cnt['o'-'a'],cnt['l'-'a']/2}));
    }
    return 0;
}
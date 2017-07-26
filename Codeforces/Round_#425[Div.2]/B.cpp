#include <bits/stdc++.h>
using namespace std;
string b;
int check;
string str;
int n;
char now[100005];
bool flag;
int len;
string f,e;
bool possi(int mode){
    if(mode){
        for(int i=0;i<f.size();i++){
            if(f[i]=='?'){
                if(check&(1<<(now[i]-'a')))
                    continue;
                else
                    return false;
            }
            else{
                if(f[i]==now[i])
                    continue;
                else
                    return false;
            }
        }
        for(int i=f.size();i<len-e.size();i++){
            if(check&(1<<(now[i]-'a')))
                return false;
        }
        for(int i=0;i<e.size();i++){
            int idx=len-e.size()+i;
            if(e[i]=='?'){
                if(check&(1<<(now[idx]-'a')))
                    continue;
                else
                    return false;
            }
            else{
                if(e[i]==now[idx])
                    continue;
                else
                    return false;
            }
        }
    }
    else{
        for(int i=0;i<len;i++){
            if(str[i]=='?'){
                if(check&(1<<(now[i]-'a')))
                    continue;
                else
                    return false;
            }
            else{
                if(str[i]==now[i])
                    continue;
                else
                    return false;
            }
        }
    }
    return true;
}
int main(){
    cin>>b;
    for(int i=0;i<b.size();i++)
        check|=(1<<(b[i]-'a'));
    cin>>str;
    for(int i=0;i<str.size();i++)
        if(str[i]=='*'){
            f=string(str.begin(),str.begin()+i);
            e=string(str.begin()+i+1,str.end());
            flag=true;
        }
    scanf("%d",&n);
    while(n--){
        scanf("%s",now);
        len=strlen(now);
        if(len==str.size()||(flag&&len+1>=str.size())){
            if(flag){
                if(possi(1))
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else{
                if(possi(0))
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
        else
            printf("NO\n");
    }
    return 0;
}
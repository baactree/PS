#include <bits/stdc++.h>
using namespace std;
const int mod=20150523;
string a,b;
int dp1[100005];
int dp2[100005];
int dp3[100005];
int dp4[100005];
int calc(string k){
    int ret=0;
    int p=0;
    bool flag=false;
    int w=0;
    int len=k.size();
    for(int i=0;i<k.size();i++){
        int t=k[i]-'0';
        if(!flag){
            if(t==3||t==6||t==9)
                flag=true;
            for(int j=0;j<t;j++){
                int q=(p+j)%3;
                if(j==3||j==6||j==9){
                    ret+=dp4[len-1-i];
                }
                else{
                    if(q==0)
                        ret+=dp2[len-1-i];
                    else
                        ret+=dp3[len-1-i];
                    ret+=dp1[len-1-i];
                }
                ret%=mod;
            }
        }
        else{
            w=(w*10+t)%mod;
        }
        p=(p+t)%3;
    }
    if(p==0||flag)
        ret++;
    return (ret+w+1)%mod;
}
int main(){
    cin>>a>>b;
    dp4[0]=dp2[0]=1;
    dp1[1]=3;
    dp2[1]=1;
    dp3[1]=3;
    dp4[1]=10;
    int r=10;
    for(int i=2;i<100005;i++){
        dp1[i]=(dp1[i-1]*7+r*3)%mod;
        dp2[i]=(dp2[i-1]+dp3[i-1]*6)%mod;
        dp3[i]=(dp2[i-1]*3+dp3[i-1]*4)%mod;
        dp4[i]=(dp4[i-1]*10)%mod;
        r*=10;
        r%=mod;
    }
    int p=calc(b);
    int q=calc(a);
    int w=0;
    int cnt=0;
    for(int i=0;i<a.size();i++){
        int t=a[i]-'0';
        if(t==3||t==6||t==9)
            w=1;
        cnt+=t;
        cnt%=3;
    }
    if(cnt==0)
        w=1;
    printf("%d\n",(p-q+w+mod)%mod);
    return 0;
}
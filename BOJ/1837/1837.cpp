#include <bits/stdc++.h>
using namespace std;
bool prime[1000005];
vector<int> p;
string input;
int k;
int calc(int mod,long long r){
    int ret=0;
    for(int i=0;i<input.size();i++){
        ret+=(r*(input[i]-'0'))%mod;
        ret%=mod;
        r*=10;
        r%=mod;
    }
    return ret;
}
int main(){
    cin>>input;
    scanf("%d",&k);
    for(int i=2;i<k;i++){
        if(!prime[i]){
            p.push_back(i);
            for(int j=i+i;j<k;j+=i)
                prime[j]=true;
        }
    }
    reverse(input.begin(),input.end());
    for(int i=0;i<p.size();i++)
        if(calc(p[i],1)==0){
            printf("BAD %d\n",p[i]);
            return 0;
        }
    printf("GOOD\n");
    return 0;
}
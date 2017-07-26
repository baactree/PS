#include <bits/stdc++.h>
using namespace std;
int n,k;
bool prime[105];
vector<int> p;
bool possi(int x){
    for(int i=0;i<p.size();i++)
        while(x%p[i]==0)
            x/=p[i];
    return x==1;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=2;i<=k;i++){
        if(!prime[i]){
            p.push_back(i);
            for(int j=i+i;j<=k;j+=i)
                prime[j]=true;
        }
    }
    int cnt=1;
    for(int i=2;i<=n;i++)
        if(possi(i))
            cnt++;
    printf("%d\n",cnt);
    return 0;
}
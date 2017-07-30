#include <bits/stdc++.h>
using namespace std;
int n,c,m;
int arr[300005];
int sz;
vector<int> cidx[10005];
vector<int> p;
int main(){
    scanf("%d%d",&n,&c);
    sz=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        cidx[arr[i]].push_back(i);
    }
    for(int i=1;i<=c;i++)
        if(cidx[i].size()>=sz)
            p.push_back(i);
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        int len=b-a+1;
        pair<int,int> max_color={0,0};
        if(len<=2*sz){
            map<int,int> mp;
            for(int j=a;j<=b;j++){
                max_color=max(max_color,{++mp[arr[j]],arr[j]});
            }
        }
        else{
            for(int i=0;i<p.size();i++){
                int col=p[i];
                int cnt=upper_bound(cidx[col].begin(),cidx[col].end(),b)-lower_bound(cidx[col].begin(),cidx[col].end(),a);
                max_color=max(max_color,{cnt,col});
            }
        }
        if(max_color.first>len/2)
            printf("yes %d\n",max_color.second);
        else
            printf("no\n");
    }
    return 0;
}
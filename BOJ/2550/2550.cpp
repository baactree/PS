#include <bits/stdc++.h>
using namespace std;
int n;
int s[10005];
int l[10005];
int idx[10005];
int len[10005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
        idx[s[i]]=i;
    }
    vector<int> lis;
    for(int i=0;i<n;i++){
        scanf("%d",&l[i]);
        int now=idx[l[i]];
        vector<int>::iterator it=upper_bound(lis.begin(),lis.end(),now);
        if(it!=lis.end()){
            *it=now;
            len[i]=it-lis.begin()+1;
        }
        else{
            lis.push_back(now);
            len[i]=lis.size();
        }
    }
    printf("%d\n",lis.size());
    vector<int> ans;
    int now=lis.size();
    for(int i=n-1;i>=0;i--){\
        if(len[i]==now){
            ans.push_back(l[i]);
            now--;
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    return 0;
}
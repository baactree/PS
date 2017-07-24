#include <bits/stdc++.h>
using namespace std;
int n;
int len;
string arr[1000];
bool possi(int x){
    set<string> s;
    for(int i=0;i<n;i++)
        if(!s.insert(string(arr[i].begin()+len-x,arr[i].end())).second)
            return false;
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    len=arr[0].size();
    int le,ri,mid,ans;
    le=1;
    ri=len;
    while(le<=ri){
        mid=(le+ri)/2;
        if(possi(mid)){
            ans=mid;
            ri=mid-1;
        }
        else
            le=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
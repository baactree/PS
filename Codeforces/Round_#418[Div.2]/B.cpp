#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int b[1000];
int ans[1000];
int main(){
    scanf("%d",&n);
    set<int> s;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        s.insert(i+1);
    }
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    vector<int> idx;
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            idx.push_back(i);
        else{
            ans[i]=a[i];
            s.erase(a[i]);
        }
    if(idx.size()==1){
        ans[idx[0]]=*s.begin();
    }
    else{
        vector<int> vec;
        for(auto it=s.begin();it!=s.end();it++)
            vec.push_back(*it);
        ans[idx[0]]=vec[0];
        ans[idx[1]]=vec[1];
        if(((ans[idx[0]]==a[idx[0]])||(ans[idx[0]]==b[idx[0]]))&&
        ((ans[idx[1]]==a[idx[1]])||(ans[idx[1]]==b[idx[1]])));
        else{
            ans[idx[0]]=vec[1];
            ans[idx[1]]=vec[0];
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
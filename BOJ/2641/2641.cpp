#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[100];
int rarr[100];
int trans[5]={0,3,4,1,2};
vector<vector<int> >  ans;
vector<int> now;
bool possi(){
    for(int i=0;i<n;i++){
        bool flag=true;
        bool rflag=true;
        for(int j=0;j<n;j++){
            if(arr[i+j]!=now[j])
                flag=false;
            if(rarr[i+j]!=now[j])
                rflag=false;
        }
        if(flag||rflag){
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        arr[i+n]=arr[i];
        rarr[i]=trans[arr[i]];
        rarr[i+n]=rarr[i];
    }
    reverse(rarr,rarr+2*n);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        now.clear();
        for(int i=0;i<n;i++){
            int in;
            scanf("%d",&in);
            now.push_back(in);
        }
        if(possi()){
            ans.push_back(now);
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m;
int mat[105][105];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mat[i][j]);
    vector<pair<int,int> > ans;
    if(n<m){
        for(int i=0;i<n;i++){
            int k=505;
            for(int j=0;j<m;j++)
                k=min(k,mat[i][j]);
            for(int j=0;j<k;j++)
                ans.push_back({0,i+1});
            for(int j=0;j<m;j++)
                mat[i][j]-=k;
        }
        for(int i=0;i<m;i++){
            int k=505;
            for(int j=0;j<n;j++)
                k=min(k,mat[j][i]);
            for(int j=0;j<k;j++)
                ans.push_back({1,i+1});
            for(int j=0;j<n;j++)
                mat[j][i]-=k;
        }
    }
    else{
        for(int i=0;i<m;i++){
            int k=505;
            for(int j=0;j<n;j++)
                k=min(k,mat[j][i]);
            for(int j=0;j<k;j++)
                ans.push_back({1,i+1});
            for(int j=0;j<n;j++)
                mat[j][i]-=k;
        }
        for(int i=0;i<n;i++){
            int k=505;
            for(int j=0;j<m;j++)
                k=min(k,mat[i][j]);
            for(int j=0;j<k;j++)
                ans.push_back({0,i+1});
            for(int j=0;j<m;j++)
                mat[i][j]-=k;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cnt+=mat[i][j];
    if(cnt!=0)
        return !printf("-1\n");
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%s %d\n",ans[i].first?"col":"row",ans[i].second);
    return 0;
}
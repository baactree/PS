#include <bits/stdc++.h>
using namespace std;
int n;
int mat[1005][1005];
pair<int,int> arr[100000];
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        memset(mat,0,sizeof(mat));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&arr[i].first,&arr[i].second);
        }
        int ans=0;
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++){
                vector<pair<int,int> > vec;
                for(int k=0;k<n;k++){
                    int x=arr[k].first+i;
                    int y=arr[k].second+j;
                    mat[x/10][y/10]++;
                    ans=max(mat[x/10][y/10],ans);
                    vec.push_back({x/10,y/10});
                    if(x!=0&&x%10==0){
                        mat[x/10-1][y/10]++;
                        ans=max(mat[x/10-1][y/10],ans);
                        vec.push_back({x/10-1,y/10});
                    }
                    if(y!=0&&y%10==0){
                        mat[x/10][y/10-1]++;
                        ans=max(mat[x/10][y/10-1],ans);
                        vec.push_back({x/10,y/10-1});
                    }
                    if(x!=0&&y!=0&&x%10==0&&y%10==0){
                        mat[x/10-1][y/10-1]++;
                        ans=max(mat[x/10-1][y/10-1],ans);
                        vec.push_back({x/10-1,y/10-1});
                    }
                }
                for(int k=0;k<vec.size();k++)
                    mat[vec[k].first][vec[k].second]=0;
            }
        printf("%d\n",ans);
    }
    return 0;  
}
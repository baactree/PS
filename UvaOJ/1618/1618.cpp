#include <bits/stdc++.h>
using namespace std;
int k;
int arr[5005];
int pre[5005];
int min_value[5005][5005];
int max_value[5005][5005];
bool possi(){
    for(int i=0;i<k;i++){
        min_value[i][i]=arr[i];
        max_value[i][i]=arr[i];
        for(int j=i+1;j<k;j++){
            min_value[i][j]=min(min_value[i][j-1],arr[j]);
            max_value[i][j]=max(max_value[i][j-1],arr[j]);
        }
    }
    for(int i=0;i<k;i++){
        memset(pre,-1,sizeof(pre));
        for(int j=i+1;j<k;j++){
            if(arr[j]<=arr[i])
                continue;
            for(int t=arr[j]-1;t>=0;t--){
                if(pre[t]!=-1)
                    break;
                pre[t]=j;
            }
            if(pre[arr[j]]==-1)
                continue;
            int le=pre[arr[j]]+1;
            int ri=j-1;
            if(le<=ri&&min_value[le][ri]<arr[i])
                return true;
        }
    }
    for(int i=0;i<k;i++){
        memset(pre,-1,sizeof(pre));
        for(int j=i+1;j<k;j++){
            if(arr[j]>=arr[i])
                continue;
            for(int t=arr[j]+1;t<k;t++){
                if(pre[t]!=-1)
                    break;
                pre[t]=j;
            }
            if(pre[arr[j]]==-1)
                continue;
            int le=pre[arr[j]]+1;
            int ri=j-1;
            if(le<=ri&&max_value[le][ri]>arr[i])
                return true;
        }
    }
    return false;
}
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&k);
        vector<int> idx;
        for(int i=0;i<k;i++){
            scanf("%d",&arr[i]);
            idx.push_back(arr[i]);
        }
        sort(idx.begin(),idx.end());
        idx.erase(unique(idx.begin(),idx.end()),idx.end());
        for(int i=0;i<k;i++){
            int p=lower_bound(idx.begin(),idx.end(),arr[i])-idx.begin();
            arr[i]=p;
        }
        printf("%s\n",possi()?"YES":"NO");
        
    }
    return 0;
}
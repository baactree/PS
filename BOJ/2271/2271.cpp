#include <bits/stdc++.h>
using namespace std;
int k;
short arr[5005];
short pre[5005];
short value[5005][5005];
bool possi(){
    for(int i=0;i<k;i++){
        value[i][i]=arr[i];
        for(int j=i+1;j<k;j++){
            value[i][j]=min(value[i][j-1],arr[j]);
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
            if(le<=ri&&value[le][ri]<arr[i]){
                return true;
            }
        }
    }
    for(int i=0;i<k;i++){
        value[i][i]=arr[i];
        for(int j=i+1;j<k;j++){
            value[i][j]=max(value[i][j-1],arr[j]);
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
            if(le<=ri&&value[le][ri]>arr[i])
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
        printf("%s\n",possi()?"Yes":"No");
    }
    return 0;
}
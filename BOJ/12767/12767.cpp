#include <bits/stdc++.h>
using namespace std;
int n,k;
bool trip[55];
set<int> s[55];
int now[2000005];
int main(){
    int ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        memset(trip,0,sizeof(trip));
        vector<int> temp;
        for(int j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            int idx=1;
            while(now[idx]!=0){
                if(now[idx]<x)
                    idx=idx*2+1;
                else
                    idx=idx*2;
            }
            now[idx]=x;
            temp.push_back(idx);
            for(int q=0;q<ans;q++)
                if(s[q].find(idx)==s[q].end())
                    trip[q]=true;
        }
        bool flag=false;
        for(int j=0;j<ans;j++)
            if(!trip[j])
                flag=true;
        for(int j=0;j<temp.size();j++)
            now[temp[j]]=0;
        if(!flag){
            for(int j=0;j<temp.size();j++){
                int idx=temp[j];
                s[ans].insert(idx);
            }
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
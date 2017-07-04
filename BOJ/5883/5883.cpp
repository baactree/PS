#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000];
vector<int> vec;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        vec.push_back(arr[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int ans=0;
    for(int i=0;i<vec.size();i++){
        int cnt=0;
        int pre=0;
        for(int j=0;j<n;j++){
            if(arr[j]==vec[i])
            continue;
            if(j==0){
                pre=arr[j];
                cnt++;
            }
            else{
                if(pre!=arr[j]){
                    pre=arr[j];
                    cnt=1;
                }
                else{
                    cnt++;
                }
            }
            ans=max(ans,cnt);
        }
    }
    printf("%d\n",ans);
    return 0;
}
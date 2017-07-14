#include <bits/stdc++.h>
using namespace std;
int arr[20];
int main(){
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        int tc;
        scanf("%d",&tc);
        for(int i=0;i<20;i++)
            scanf("%d",&arr[i]);
        int ans=0;
        vector<int> vec;
        for(int i=0;i<20;i++){
            auto it=upper_bound(vec.begin(),vec.end(),arr[i]);
            if(it==vec.end())
                vec.push_back(arr[i]);
            else{
                int idx=it-vec.begin();
                ans+=vec.size()-idx;
                vec.insert(it,arr[i]);
            }
        }
        printf("%d %d\n",tc,ans);
    }
}
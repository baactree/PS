#include "bits/stdc++.h"
using namespace std;
int A[4000],B[4000],C[4000],D[4000];
int N;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
    vector<int> AB;
    vector<int> CD;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
    }
    int ans=0;
    sort(CD.begin(),CD.end());
    for(int i=0;i<AB.size();i++){
        auto range=equal_range(CD.begin(),CD.end(),-AB[i]);
        ans+=range.second-range.first;
    }
    cout<<ans<<endl;
    return 0;
}
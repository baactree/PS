#include "bits/stdc++.h"
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    vector<int> arr;
    for(int i=0;i<N;i++){
        int in;
        scanf("%d",&in);
        vector<int>::iterator it=lower_bound(arr.begin(),arr.end(),in);
        if(it==arr.end())
            arr.push_back(in);
        else
            *it=in;
    }
    printf("%d\n",arr.size());
    return 0;
}
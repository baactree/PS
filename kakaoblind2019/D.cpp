#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
map<int,int> mp;
int solution(vector<int> arr, long long k) {
    mp.clear();
    n=arr.size();
    ll sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        mp[arr[i]]++;
    }
    if(k>=sum)return -1;
    int len=n;
    int cur=0;
    for(auto it:mp){
        ll nh=it.first-cur;
        if(nh*len<=k)k-=nh*len;
        else{
            k%=len;
            for(int i=0;i<n;i++){
                if(arr[i]<=cur)continue;
                if(k==0)return i+1;
                k--;
            }
        }
        len-=it.second;
        cur=it.first;
    }
    return -1;
}
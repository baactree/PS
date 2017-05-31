#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int l;
vector<pair<int,int> > arr;
bool cmp(const pair<int,int> a,const pair<int,int> b){
    return a.first+a.second<b.first+b.second;
}
int main(){

    for(int i=1;i*i<=1e6;i++){
        for(int j=1;j<i;j++){
            if(((i+j)&1)&&gcd(i,j)==1){
                int a=2*i*j;
                int b=i*i-j*j;
                if(a>b) swap(a,b);
                arr.push_back({a,b});
            }
        }
    }
    sort(arr.begin(),arr.end(),cmp);
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        scanf("%d",&l);
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(l<(arr[i].first+arr[i].second)*2) break;
            l-=(arr[i].first+arr[i].second)*2;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
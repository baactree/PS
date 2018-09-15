#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<int> stages) {
    vector<int> cnt(n+2),sum(n+2);
    for(int i=0;i<stages.size();i++)
        cnt[stages[i]]++;
    sum[n+1]=cnt[n+1];
    for(int i=n;i>=1;i--)
        sum[i]=cnt[i]+sum[i+1];
    vector<pair<double,int> > vec;
    for(int i=1;i<=n;i++){
        if(!sum[i])vec.push_back({0,i});
        else vec.push_back({(double)cnt[i]/sum[i],i});
    }
    sort(vec.begin(),vec.end(),[](pair<double,int> &a,pair<double,int> &b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    });
    vector<int> answer;
    for(int i=0;i<vec.size();i++)
        answer.push_back(vec[i].second);
    return answer;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
vector<pair<int,int> > y[100005];
vector<int> yidx;
vector<int> temp;
void get_tree(int idx, int le,int ri,pair<int,int> now){
    if(idx+1==yidx.size())return;
    auto lit=lower_bound(y[yidx[idx+1]].begin(),y[yidx[idx+1]].end(),make_pair(le,0));
    if(lit!=y[yidx[idx+1]].end()&&lit->first<now.first){
        adj[now.second].push_back(lit->second);
        get_tree(idx+1,le,now.first-1,*lit);
    }
    auto rit=lower_bound(y[yidx[idx+1]].begin(),y[yidx[idx+1]].end(),make_pair(now.first+1,0));
    if(rit!=y[yidx[idx+1]].end()&&rit->first<=ri){
        adj[now.second].push_back(rit->second);
        get_tree(idx+1,now.first+1,ri,*rit);
    }
}
void pre(int now){
    temp.push_back(now);
    for(auto &there:adj[now])pre(there);
}
void post(int now){
    for(auto &there:adj[now])post(there);
    temp.push_back(now);
}
vector<vector<int>> solution(vector<vector<int>> arr) {
    for(int i=0;i<10005;i++)adj[i].clear();
    yidx.clear();
    for(int i=0;i<100005;i++)y[i].clear();
    
    for(int i=0;i<arr.size();i++){
        yidx.push_back(arr[i][1]);
        y[arr[i][1]].push_back({arr[i][0],i+1});
    }
    sort(yidx.begin(),yidx.end(),[](int a,int b){
        return a>b;
    });
    yidx.erase(unique(yidx.begin(),yidx.end()),yidx.end());
    for(int i=0;i<100005;i++)sort(y[i].begin(),y[i].end());
    pair<int,int> root=y[yidx[0]][0];
    get_tree(0,0,100000,root);
    vector<vector<int> > ans;
    temp.clear();
    pre(root.second);
    ans.push_back(temp);
    temp.clear();
    post(root.second);
    ans.push_back(temp);
    return ans;
}
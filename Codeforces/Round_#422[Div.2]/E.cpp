#include <bits/stdc++.h>
using namespace std;
int dp[100005][35];
vector<int> sa[20];
struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& group, int t) :group(group), t(t) {}
    const bool operator () (int a, int b) {
        if (group[a] != group[b])
            return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};
void get_suffix_array(const string& s) {
    int n = s.length();
    int t = 1;
    int idx = 0;
    vector<int> group(n + 1);
    for (int i = 0; i < n; i++){
        group[i] = s[i];
    }
    group[n] = -1;
    sa[idx]=group;
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i;
    while (true) {
        idx++;
        Comparator cmp(group, t);
        sort(perm.begin(), perm.end(), cmp);
        t <<= 1;
        if (t >= n)
            break;
        vector<int> newGroup(n + 1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (cmp(perm[i - 1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i - 1]];
        }
        sa[idx] = group = newGroup;
    }
}
string str;
int get_lcp(int i,int j){
    int ret=0;
    for(int k=19;k>=0;k--){
        if(sa[k].empty())
            continue;
        if(i+(1<<k)<=str.size()&&j+(1<<k)<=str.size()&&sa[k][i]==sa[k][j]){
            ret+=(1<<k);
            i+=(1<<k);
            j+=(1<<k);
        }
    }
    return ret;
}
int main(){
    int n,m,x;
    string s,t;
    cin>>n>>s>>m>>t>>x;
    str=s+'#'+t;
    get_suffix_array(str);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=x;j++){
            if(dp[i][j]==-1)
                continue;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j<x){
                int lcp=get_lcp(i,dp[i][j]+n+1);
                dp[i+lcp][j+1]=max(dp[i+lcp][j+1],dp[i][j]+lcp);
            }
        }
    bool flag=false;
    for(int i=0;i<=x;i++)
        if(dp[n][i]==m)
            flag=true;
    printf("%s\n",flag?"YES":"NO");
    return 0;
}
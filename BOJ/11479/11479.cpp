#include <bits/stdc++.h>
using namespace std;
vector<int> get_sa(const string &str){
    int n=str.size();
    vector<int> sa(n);
    vector<int> g(n+1,-1);
    for(int i=0;i<n;i++){
        sa[i]=i;
        g[i]=str[i];
    }
    for(int t=1;t<n;t<<=1){
        auto cmp=[&](const int &a,const int &b){
            if(g[a]==g[b])
                return g[a+t]<g[b+t];
            return g[a]<g[b];
        };
        sort(sa.begin(),sa.end(),cmp);
        vector<int> ng(n+1,-1);
        ng[sa[0]]=0;
        for(int i=1;i<n;i++)
            if(cmp(sa[i-1],sa[i]))
                ng[sa[i]]=ng[sa[i-1]]+1;
            else
                ng[sa[i]]=ng[sa[i-1]];
        g=ng;
    }
    return sa;
}
vector<int> get_lcp_array(const vector<int> &sa, const string &str){
	int n=str.size();
    vector<int> lcp(n,0),rank(n);
    for(int i=0;i<n;i++)
        rank[sa[i]]=i;
    int len=0;
    for(int i=0;i<n;i++){
        int k=rank[i];
        if(k){
            int j=sa[k-1];
            while(str[i+len]==str[j+len])
                len++;
            lcp[k]=len;
            len=max(0,len-1);
        }
    }
    return lcp;
}
int main(){
    string str;
    cin>>str;
    vector<int> sa=get_sa(str);
    // for(int i=0;i<sa.size();i++)
    //     printf("%d ",sa[i]);
    // printf("\n");
    vector<int> lcp=get_lcp_array(sa,str);
    long long sum=str.size()*(str.size()+1)/2;
    for(int i=0;i<lcp.size();i++){
        // cout<<lcp[i]<<" "<<sa[i]<<endl;
        sum-=lcp[i];
    }
    cout<<sum<<endl;
    return 0;
}
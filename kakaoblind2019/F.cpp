#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
int n;
vector<vector<int> > adj;
string get_link(string now){
    string f="<meta property=\"og:url\" content=\"";
    int st=now.find(f);
    int ed=now.find("\"",st+f.size());
    return string(now.begin()+st+f.size(),now.begin()+ed);
}
int get_wrd_cnt(string wrd,string str){
    if(str.empty())return 0;
    str.push_back('*');
    int ret=0;
    string cur="";
    for(int i=0;i<str.size();i++){
        str[i]=tolower(str[i]);
        if(str[i]>='a'&&str[i]<='z'){
            cur+=str[i];
        }
        else{
            if(wrd==cur)ret++;
            cur="";
        }
    }
    return ret;
}
int solution(string wrd, vector<string> arr) {
    for(int i=0;i<wrd.size();i++)
        wrd[i]=tolower(wrd[i]);
    mp.clear();
    n=arr.size();
    vector<int> sc(n),lcnt(n);
    vector<double> mc(n);
    adj=vector<vector<int> > (n);
    for(int i=0;i<n;i++){
        string link=get_link(arr[i]);
        mp[link]=i;
    }
    for(int i=0;i<n;i++){
        string f="<a href=\"";
        int st=arr[i].find("<body>")+6;
        while(true){
            int nst=arr[i].find(f,st);
            if(nst==string::npos)break;
            sc[i]+=get_wrd_cnt(wrd,string(arr[i].begin()+st,arr[i].begin()+nst));
            int ed=arr[i].find("\"",nst+f.size());
            string now=string(arr[i].begin()+nst+f.size(),arr[i].begin()+ed);
            lcnt[i]++;
            if(mp.count(now)>0)adj[mp[now]].push_back(i);
            st=arr[i].find("</a>",ed)+4;
        }
        int ed=arr[i].find("</body>",st);
        sc[i]+=get_wrd_cnt(wrd,string(arr[i].begin()+st,arr[i].begin()+ed));
    }
    for(int i=0;i<n;i++){
        mc[i]+=sc[i];
        for(auto &there:adj[i])mc[i]+=(double)sc[there]/lcnt[there];
    }
    vector<pair<double,int> > ans;
    for(int i=0;i<n;i++){
        ans.push_back({mc[i],i});
    }
    sort(ans.begin(),ans.end(),[](pair<double,int> a,pair<double,int> b){
        if(a.first==b.first)return a.second<b.second;
        return a.first>b.first;
    });
    return ans[0].second;
}
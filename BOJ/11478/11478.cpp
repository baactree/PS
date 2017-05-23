// =====================================================================================
// 
//       Filename:  11478.cpp
//        Created:  2017년 05월 23일 11시 49분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> get_suffix_array(const string &str){
	int n=str.size();
	vector<int> perm(n), g(n+1);
	g[n]=-1;
	for(int i=0;i<n;i++){
		perm[i]=i;
		g[i]=str[i];
	}
	for(int t=1;t<n;t*=2){
		auto cmp = [&](const int &a, const int &b){
			if(g[a]!=g[b])
				return g[a]<g[b];
			return g[a+t]<g[b+t];
		};
		sort(perm.begin(), perm.end(), cmp);
		vector<int> ng(n+1, 0);
		ng[n]=-1;
		for(int i=1;i<n;i++)
			if(cmp(perm[i-1], perm[i]))
				ng[perm[i]]=ng[perm[i-1]]+1;
			else
				ng[perm[i]]=ng[perm[i-1]];
		g=ng;
	}
	return perm;
}
vector<int> get_lcp_array(const vector<int> &sa, const string &str){
	int n=str.size();
	vector<int> rank(n);
	vector<int> lcp(n, 0);
	for(int i=0;i<n;i++)
		rank[sa[i]]=i;
	int len=0;
	for(int i=0;i<n;i++){
		int k=rank[i];
		if(k){
			int j=sa[k-1];
			while(str[j+len]==str[i+len])
				len++;
			lcp[k]=len;
			len=max(0, len-1);
		}
	}
	return lcp;
}
int main(){
	string str;
	cin>>str;
	vector<int> sa=get_suffix_array(str);
	vector<int> lcp=get_lcp_array(sa, str);
	int sum=0;
	for(int i=0;i<lcp.size();i++)
		sum+=lcp[i];
	int n=str.size();
	printf("%d\n", (n*(n+1))/2-sum);
	return 0;
}


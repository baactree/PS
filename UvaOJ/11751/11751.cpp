// =====================================================================================
// 
//       Filename:  11751.cpp
//        Created:  2017년 06월 27일 18시 34분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt[30000];
vector<int> adj[1005];
int main(){
	while(scanf("%d%d", &n, &m)==2){
		if(n==0&&m==0)
			break;
		for(int i=0;i<1005;i++)
			adj[i].clear();
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<m;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(i);
			adj[b].push_back(i);
			cnt[i]+=2;
		}
		string ans="";
		for(int i=n-1;i>=0;i--){
			int k=0x3f3f3f3f;
			for(int j=0;j<adj[i].size();j++)
				k=min(k, cnt[adj[i][j]]);
			if(k>1){
				ans+="0";
				for(int j=0;j<adj[i].size();j++)
					cnt[adj[i][j]]--;
			}
			else{
				ans+="1";
			}
		}
		reverse(ans.begin(), ans.end());
		cout<<ans<<'\n';
	}
	return 0;
}


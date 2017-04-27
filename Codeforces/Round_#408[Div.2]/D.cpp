// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 04월 25일 23시 17분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k, d;
int arr[300005];
bool trip[300005];
vector<pair<int, int> > adj[300005];
vector<int> ans;
int main(){
	scanf("%d%d%d", &n, &k, &d);
	for(int i=0;i<k;i++){
		int in;
		scanf("%d", &in);
		arr[in]=true;
	}
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back({b, i+1});
		adj[b].push_back({a, i+1});
	}
	queue<pair<int, int> > q;	
	for(int i=1;i<=n;i++)
		if(arr[i]){
			q.push({i, 0});
			trip[i]=true;
		}
	while(!q.empty()){
		int now=q.front().first;
		int par=q.front().second;
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int idx=adj[now][i].second;
			if(there==par)
				continue;
			if(trip[there]){
				ans.push_back(idx);
				continue;
			}
			q.push({there, now});
			trip[there]=true;
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	return 0;
}


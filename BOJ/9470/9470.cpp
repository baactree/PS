// =====================================================================================
// 
//       Filename:  9470.cpp
//        Created:  2017년 04월 15일 12시 21분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k, n, m;
vector<vector<int> > adj;
vector<int> strahler;
int dfs(int now){
	int ret=0;
	int cnt=0;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(strahler[there]==-1){
			int temp=dfs(there);
			if(ret<temp){
				cnt=1;
				ret=temp;
			}
			else if(ret==temp)
				cnt++;
		}
		else{
			if(ret<strahler[there]){
				cnt=1;
				ret=strahler[there];
			}
			else if(ret==strahler[there])
				cnt++;
		}
	}
	if(cnt>1)
		ret++;
	if(ret==0)
		ret++;
	return strahler[now]=ret;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d%d%d", &k, &n, &m);
		adj=vector<vector<int> >(n+1);
		strahler=vector<int>(n+1, -1);
		for(int i=0;i<m;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			adj[b].push_back(a);
		}
		printf("%d %d\n", k, dfs(n));
	}
	return 0;
}


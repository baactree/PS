// =====================================================================================
// 
//       Filename:  happy.cpp
//        Created:  2017년 04월 10일 18시 56분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
int n, m;
int trip[201];
//모순이 발생하는 경우 true를 리턴함
bool dfs(int now, int type){
	trip[now]=type;
	bool ret=false;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		//이미 방문한 정점인데
		if(trip[there]!=-1){
			//현재 정점과 타입이 같다면
			if(trip[there]==type)
				return true;
			continue;
		}
		ret|=dfs(there, 1-type);
	}
	return ret;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		adj.clear();
		scanf("%d%d", &n, &m);
		adj=vector<vector<int> >(n+1);
		//인접리스트 그래프 입력
		for(int i=0;i<m;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool ans=false;
		//방문 체크
		memset(trip, -1, sizeof(trip));
		for(int i=1;i<=n;i++){
			//방문하지 않은 모든 정점에 대하여 모순을 계산
			if(trip[i]==-1)
				ans|=dfs(i, 0);
		}
		printf("Case #%d\n%d\n", tc, !ans);
	}
	return 0;
}


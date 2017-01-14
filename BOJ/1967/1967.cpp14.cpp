#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <vector>


using namespace std;
vector<pair<int, int> >Map[10001];
int N;
bool trip[10001];
int l_v, l_d;
void dfs(int v,int depth){
	trip[v] = true;
	if (l_d < depth){
		l_d = depth;
		l_v = v;
	}
	int size = Map[v].size();
	for (int i = 0; i < size; i++){
		if (!trip[Map[v][i].first])
			dfs(Map[v][i].first, Map[v][i].second + depth);
	}
}
int main(){
	cin >> N;
	int a,b, d;
	for (int i = 0; i < N - 1; i++){
		scanf("%d%d%d", &a, &b,&d);
		Map[a].push_back(make_pair(b, d));		
		Map[b].push_back(make_pair(a, d));
	}
	l_d = -1;
	dfs(1,0);
	l_d = -1;
	memset(trip, 0, sizeof(trip));
	dfs(l_v, 0);
	printf("%d\n", l_d);
	return 0; 
}
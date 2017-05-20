// =====================================================================================
// 
//       Filename:  2191.cpp
//        Created:  2017년 05월 20일 12시 06분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<double, double> arr[100];
int n, m, s, v;
vector<int> adj[100];
int level[100];
bool trip[100];
int matched[100];
void bfs(){
	memset(level, -1, sizeof(level));
	queue<int> q;
	for(int i=0;i<n;i++)
		if(!trip[i]){
			q.push(i);
			level[i]=0;
		}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			if(matched[there]!=-1&&level[matched[there]]==-1){
				level[matched[there]]=level[now]+1;
				q.push(matched[there]);
			}
		}
	}
}
bool dfs(int now){
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(matched[there]==-1||(level[matched[there]]==level[now]+1&&dfs(matched[there]))){
			matched[there]=now;
			trip[now]=true;
			return true;
		}
	}
	return false;
}
int flow(){
	int ret=0;
	memset(matched, -1, sizeof(matched));
	memset(trip, 0, sizeof(trip));
	while(true){
		bfs();
		int f=0;
		for(int i=0;i<n;i++)
			if(!trip[i]&&dfs(i))
				f++;
		if(f==0)
			break;
		ret+=f;
	}
	return ret;
}
double dist(pair<double, double> a, pair<double, double> b){
	double x=a.first-b.first;
	double y=a.second-b.second;
	return sqrt(x*x+y*y);
}
int main(){
	scanf("%d%d%d%d", &n, &m, &s, &v);
	for(int i=0;i<n;i++)
		scanf("%lf%lf", &arr[i].first, &arr[i].second);
	for(int i=0;i<m;i++){
		pair<double, double> in;
		scanf("%lf%lf", &in.first, &in.second);
		for(int j=0;j<n;j++){
			if(dist(arr[j], in)<=s*v)
				adj[j].push_back(i);
		}
	}
	printf("%d\n", n-flow());
	return 0;
}


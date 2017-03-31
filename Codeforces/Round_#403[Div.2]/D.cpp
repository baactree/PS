// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 03월 31일 16시 11분 16초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
int n;
vector<pair<int, int> > adj[2000];
int matcheda[2000];
int matchedb[2000];
char name[1000];
char hname[1000];
bool trip[2000];
vector<string> vec;
bool dfs(int x){
	if(trip[x])
		return false;
	trip[x]=true;
	int cnt=0;
	for(int i=0;i<adj[x].size();i++){
		int theretype=adj[x][i].second;
		if(theretype==0)
			cnt++;
	}
	for(int i=0;i<adj[x].size();i++){
		int there=adj[x][i].first;
		int theretype=adj[x][i].second;
		if(cnt>1){
			if(theretype==0)
				continue;
		}
		if(matchedb[there]==-1||dfs(matchedb[there])){
			matchedb[there]=x;
			matcheda[x]=there;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%s%s", name, hname);
		string na, hn;
		na=name;
		na=string(na.begin(), na.begin()+3);
		hn=na;
		hn[2]=hname[0];
		int a, b;
		bool flag=false;
		if(m.count(na)==0){
			a=m.size();
			m[na]=a;
			vec.push_back(na);
		}
		else
			a=m[na];
		if(m.count(hn)==0){
			b=m.size();
			m[hn]=b;
			vec.push_back(hn);
		}
		else
			b=m[hn];
		adj[a].push_back({i, 0});
		adj[b].push_back({i, 1});

	}
	memset(matcheda, -1, sizeof(matcheda));
	memset(matchedb, -1, sizeof(matchedb));
	int f=0;
	for(int i=0;i<vec.size();i++){
		memset(trip, 0, sizeof(trip));
		if(dfs(i))
			f++;
	}
	if(f==n){
		printf("YES\n");
		for(int i=0;i<n;i++)
			cout<<vec[matchedb[i]]<<'\n';
	}
	else
		printf("NO\n");
	return 0;
}

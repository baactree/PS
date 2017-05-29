// =====================================================================================
// 
//       Filename:  2593.cpp
//        Created:  2017년 05월 29일 23시 23분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> arr[101];
int st, fi;
int dist[100105];
int par[100105];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	scanf("%d%d", &st, &fi);
	memset(dist, -1, sizeof(dist));
	dist[st]=0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now<=n){
			for(int i=1;i<=m;i++){
				if(now>=arr[i].first&&(now-arr[i].first)%arr[i].second==0&&dist[n+i]==-1){
					dist[n+i]=dist[now]+1;
					q.push(n+i);
					par[n+i]=now;
				}
			}
		}
		else{
			now-=n;
			for(int i=arr[now].first;i<=n;i+=arr[now].second){
				if(dist[i]==-1){
					dist[i]=dist[now+n]+1;
					q.push(i);
					par[i]=now+n;
				}
			}
		}
	}
	if(dist[fi]==-1){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", dist[fi]/2);
	int now=fi;
	vector<int> path;
	while(now!=st){
		if(now>n){
			path.push_back(now-n);
		}
		now=par[now];
	}
	reverse(path.begin(), path.end());
	for(int i=0;i<path.size();i++)
		printf("%d\n", path[i]);
	return 0;
}


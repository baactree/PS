// =====================================================================================
// 
//       Filename:  12130.cpp
//        Created:  2017년 05월 17일 10시 27분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[500][500];
int par[300000];
int mh[300000];
int h, w, d;
vector<vector<pair<int, int> > >  arr;
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	mh[y]=max(mh[y], mh[x]);
	par[x]=y;
}
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<h&&y>=0&&y<w;
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d%d", &h, &w, &d);
		assert(h>=1&&h<=500);
		assert(w>=1&w<=500);
		assert(d>=1&&d<=1000000000);
		vector<int> sh;
		arr.clear();
		arr.resize(h*w);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				scanf("%d", &mat[i][j]);
				assert(mat[i][j]>=0&&mat[i][j]<=1000000000);
				par[i*w+j]=i*w+j;
				mh[i*w+j]=mat[i][j];
				sh.push_back(mat[i][j]);
			}
		sort(sh.begin(), sh.end());
		sh.erase(unique(sh.begin(), sh.end()), sh.end());
		priority_queue<pair<int, pair<int, int> > > pq;
		assert(sh.size()<=h*w&&sh.size()>0);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				int idx=lower_bound(sh.begin(), sh.end(), mat[i][j])-sh.begin();
				assert(idx<h*w&&idx>=0);
				arr[idx].push_back({i, j});
				pq.push({mat[i][j], {i, j}});
			}
		int ans=0;
		for(int i=(int)sh.size()-1;i>=0;i--){
			assert(i<sh.size());
			int now=sh[i];
			while(!pq.empty()&&pq.top().first>=now+d){
				int x=pq.top().second.first;
				int y=pq.top().second.second;
				pq.pop();
				if(mat[x][y]==mh[find(x*w+y)])
					ans++;
			}
			assert(i<arr.size());
			for(int j=0;j<arr[i].size();j++){
				int x=arr[i][j].first;
				int y=arr[i][j].second;
				for(int k=0;k<4;k++){
					int nx=x+dx[k];
					int ny=y+dy[k];
					if(safe(nx, ny)&&mat[nx][ny]>=mat[x][y]){
						assert(nx*w+ny<h*w);
						merge(x*w+y, nx*w+ny);
					}
				}
			}
		}
		while(!pq.empty()){
			int x=pq.top().second.first;
			int y=pq.top().second.second;
			pq.pop();
			if(mat[x][y]==mh[find(x*w+y)])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  2933.cpp
//        Created:  2017년 06월 27일 11시 36분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, c, n;
char mat[105][105];
int trip[105][105];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool safe(int x, int y){
	return x>=0&&x<r&&y>=0&&y<c;
}
void dfs(int x, int y, int idx, vector<pair<int, int> > &arr){
	if(trip[x][y]!=-1)
		return;
	trip[x][y]=idx;
	arr.push_back({x, y});
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&mat[nx][ny]=='x'&&trip[nx][ny]==-1){
			dfs(nx, ny, idx, arr);
		}
	}
}
void possi(vector<pair<int, int> > &arr, int idx){
	vector<int> ret(arr.size(), 0);
	for(int i=0;i<arr.size();i++){
		int x=arr[i].first;
		int y=arr[i].second;
		mat[x][y]='.';
	}
	for(int i=0;i<arr.size();i++){
		int x=arr[i].first;
		int y=arr[i].second;
		int cnt=0;
		while(true){
			int nx=x+1;
			int ny=y;
			if(safe(nx, ny)&&mat[nx][ny]=='.'){
				x=nx;
				y=ny;
				cnt++;
			}
			else
				break;
		}
		ret[i]=cnt;
	}
	int k=*min_element(ret.begin(), ret.end());
	for(int i=0;i<arr.size();i++){
		int x=arr[i].first;
		int y=arr[i].second;
		mat[x+k][y]='x';
	}
}
void calc(){
	vector<vector<pair<int, int> > > comp;
	int cnt=0;
	memset(trip, -1, sizeof(trip));
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if(mat[i][j]=='x'&&trip[i][j]==-1){
				vector<pair<int, int> > now;
				dfs(i, j, cnt, now);
				comp.push_back(now);
				cnt++;
			}
		}
	for(int i=0;i<comp.size();i++){
		possi(comp[i], i);
	}
}
int main(){
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		scanf("%s", mat[i]);
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d", &k);
		k=r-k;
		if(i&1){
			for(int j=c-1;j>=0;j--){
				if(mat[k][j]=='x'){
					mat[k][j]='.';
					break;
				}
			}
		}
		else{
			for(int j=0;j<c;j++){
				if(mat[k][j]=='x'){
					mat[k][j]='.';
					break;
				}
			}
		}
		calc();
	}
	for(int i=0;i<r;i++)
		printf("%s\n", mat[i]);
	return 0;
}


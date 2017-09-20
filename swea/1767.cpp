// =====================================================================================
// 
//       Filename:  1767.cpp
//        Created:  2017년 09월 20일 18시 43분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int mat[12][12];
int cnt, len;
const int inf=0x3f3f3f3f;
vector<pair<int, int> > vec;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
inline bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<n;
}
void solve(int idx, int c, int l){
	if(idx==vec.size()){
		if(cnt<c){
			cnt=c;
			len=l;
		}
		else if(cnt==c){
			len=min(len, l);
		}
		return;
	}	
	if(vec.size()-idx+c<cnt)
		return;
	if(vec.size()-idx+c==cnt&&l>=len)
		return;
	int x=vec[idx].first;
	int y=vec[idx].second;
	for(int i=0;i<4;i++){
		int m=1;
		int len=0;
		int nx=x+dx[i];
		int ny=y+dy[i];
		while(safe(nx, ny)){
			mat[nx][ny]++;
			m=max(m, mat[nx][ny]);
			nx=nx+dx[i];
			ny=ny+dy[i];
			len++;
		}
		if(m==1)
			solve(idx+1, c+1, l+len);
		nx=x+dx[i];
		ny=y+dy[i];
		while(safe(nx, ny)){
			mat[nx][ny]--;
			nx=nx+dx[i];
			ny=ny+dy[i];
		}
	}
	solve(idx+1, c, l);
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int tc=1;tc<=testcase;tc++){
		scanf("%d", &n);
		vec.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%d", &mat[i][j]);
				if(mat[i][j])
					vec.push_back({i, j});
			}
		cnt=0;
		len=inf;
		solve(0, 0, 0);
		printf("#%d %d\n", tc, len);
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  2842.cpp
//        Created:  2017년 04월 10일 18시 19분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[50][50];
char m[50][51];
vector<int> val;
int n;
pair<int, int> st;
vector<pair<int, int> > k;
bool trip[50][50];
int dx[8]={-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8]={0, 0, -1, 1, -1, 1, 1, -1};
bool safe(int x, int y){
	return x>=0&&x<n&&y>=0&&y<n;
}
bool possi(int x, int v){
	memset(trip, 0, sizeof(trip));
	queue<pair<int, int> > q;
	if(mat[st.first][st.second]>=v&&mat[st.first][st.second]<=v+x){
		q.push(st);
		trip[st.first][st.second]=true;
	}
	while(!q.empty()){
		int nx=q.front().first;
		int ny=q.front().second;
		q.pop();
		for(int i=0;i<8;i++){
			int tx=nx+dx[i];
			int ty=ny+dy[i];
			if(safe(tx, ty)&&!trip[tx][ty]&&mat[tx][ty]>=v&&mat[tx][ty]<=v+x){
				trip[tx][ty]=true;
				q.push({tx, ty});
			}
		}
	}
	bool ret=true;
	for(int i=0;i<k.size();i++)
		if(!trip[k[i].first][k[i].second])
			ret=false;
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", m[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(m[i][j]=='P')
				st={i, j};
			else if(m[i][j]=='K')
				k.push_back({i, j});
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%d", &mat[i][j]);
			val.push_back(mat[i][j]);
		}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	int ans=0x3f3f3f3f;
	for(int i=0;i<val.size();i++){
		int le, ri, mid;
		le=0, ri=1000000;
		while(le<=ri){
			mid=(le+ri)/2;
			if(possi(mid, val[i])){
				ans=min(ans, mid);
				ri=mid-1;
			}
			else
				le=mid+1;
		}
	}
	printf("%d\n", ans);
	return 0;
}


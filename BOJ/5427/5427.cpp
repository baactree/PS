// =====================================================================================
// 
//       Filename:  5427.cpp
//        Created:  2017년 02월 20일 18시 45분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char Map[1000][1001];
int W, H;
bool trip[1000][1000];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
extern inline bool safe(int x, int y){
	return x>=0&&x<H&&y>=0&&y<W;
}
struct Node{
	int x, y, t;
};
int main(){
	int Case;
	scanf("%d", &Case);
	while(Case--){
		memset(trip, 0, sizeof(trip));
		scanf("%d%d", &W, &H);
		for(int i=0;i<H;i++)
			scanf("%s", Map[i]);
		queue<Node> q;
		queue<pair<int, int> > f;
		for(int i=0;i<H;i++)
			for(int j=0;j<W;j++){
				if(Map[i][j]=='*'){
					f.push({i, j});
					trip[i][j]=true;
				}
				if(Map[i][j]=='@'){
					q.push({i, j, 0});
					trip[i][j]=true;
				}
			}
		int ans=0x3f3f3f3f;
		while(!q.empty()){
			int now=f.size();
			while(now--){
				int x=f.front().first;
				int y=f.front().second;
				f.pop();
				for(int i=0;i<4;i++){
					int nx=x+dx[i];
					int ny=y+dy[i];
					if(safe(nx, ny)&&Map[nx][ny]=='.'||Map[nx][ny]=='@'){
						Map[nx][ny]='*';
						trip[nx][ny]==true;
						f.push({nx, ny});
					}
				}
			}
			now=q.size();
			while(now--){
				int x=q.front().x;
				int y=q.front().y;
				int t=q.front().t;
				q.pop();
				for(int i=0;i<4;i++){
					int nx=x+dx[i];
					int ny=y+dy[i];
					if(safe(nx, ny)){
						if(!trip[nx][ny]&&Map[nx][ny]=='.'){
							trip[nx][ny]=true;
							q.push({nx, ny, t+1});
						}
					}
					else{
						ans=min(ans, t+1);
					}
				}
			}
		}
		if(ans==0x3f3f3f3f)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}


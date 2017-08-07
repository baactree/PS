// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 08월 05일 13시 05분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

bool trip[105][105];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int M, N;
bool safe(int x, int y){
	return x>=0&&x<M&&y>=0&&y<N;
}
int dfs(int x, int y, const vector<vector<int> > &mat){
	trip[x][y]=true;
	int ret=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(safe(nx, ny)&&!trip[nx][ny]&&mat[x][y]==mat[nx][ny])
			ret+=dfs(nx, ny, mat);
	}
	return ret;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	M=m;
	N=n;
	memset(trip, 0, sizeof(trip));
    int number_of_area = 0;
    int max_size_of_one_area = 0;
   	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(picture[i][j]&&!trip[i][j]){
				number_of_area++;
				max_size_of_one_area=max(max_size_of_one_area, dfs(i, j,picture));
			}
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}



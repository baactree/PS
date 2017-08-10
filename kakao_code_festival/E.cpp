// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 08월 05일 16시 53분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int sum[5005][5005];
vector<int> xidx;
vector<int> yidx;
int get_cnt(int sx, int sy, int fx, int fy){
	if(sx>fx||sy>fy)
		return 0;
	return sum[fx][fy]-sum[sx-1][fy]-sum[fx][sy-1]+sum[sx-1][sy-1];
}
int solution(int n, vector<vector<int>> mat) {
	memset(sum, 0, sizeof(sum));
	xidx.clear();
	yidx.clear();
	xidx.push_back(-1);
	yidx.push_back(-1);
	for(int i=0;i<n;i++){
		int x=mat[i][0];
		int y=mat[i][1];
		xidx.push_back(x);
		yidx.push_back(y);
	}
	sort(xidx.begin(), xidx.end());
	sort(yidx.begin(), yidx.end());
	xidx.erase(unique(xidx.begin(), xidx.end()), xidx.end());
	yidx.erase(unique(yidx.begin(), yidx.end()), yidx.end());
	for(int i=0;i<n;i++){
		int x=lower_bound(xidx.begin(), xidx.end(), mat[i][0])-xidx.begin();
		int y=lower_bound(yidx.begin(), yidx.end(), mat[i][1])-yidx.begin();
		sum[x][y]++;
		mat[i][0]=x;
		mat[i][1]=y;
	}
	for(int i=1;i<5005;i++)
		for(int j=1;j<5005;j++)
			sum[i][j]=sum[i][j-1]+sum[i][j];
	for(int i=1;i<5005;i++)
		for(int j=1;j<5005;j++)
			sum[j][i]=sum[j-1][i]+sum[j][i];
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(mat[i][0]==mat[j][0]||mat[i][1]==mat[j][1])
				continue;
			int sx, sy, fx, fy;
			sx=min(mat[i][0], mat[j][0]);
			sy=min(mat[i][1], mat[j][1]);
			fx=max(mat[i][0], mat[j][0]);
			fy=max(mat[i][1], mat[j][1]);
			sx++;sy++;
			fx--;fy--;
			int cnt=get_cnt(sx, sy, fx, fy);
			if(cnt==0)
				ans++;
		}
	}
    return ans;
}
int main(){

	return 0;
}


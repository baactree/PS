// =====================================================================================
// 
//       Filename:  2339.cpp
//        Created:  2017년 06월 09일 17시 38분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int mat[20][20];
int solve(int x1, int y1, int x2, int y2, int pre){
	vector<pair<int, int> > p;
	int cnt=0;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++){
			if(mat[i][j]==1)
				p.push_back({i, j});
			else if(mat[i][j]==2)
				cnt++;
		}
	if(p.size()==0){
		return cnt==1;
	}
	int ret=0;
	for(int i=0;i<p.size();i++){
		int x=p[i].first;
		int y=p[i].second;
		if(pre==-1||pre==0){
			bool flag=false;
			for(int j=y1;j<=y2;j++)
				if(mat[x][j]==2)
					flag=true;
			if(!flag)
				ret+=solve(x1, y1, x-1, y2, 1)*solve(x+1, y1, x2, y2, 1);
		}
		if(pre==-1||pre==1){
			bool flag=false;
			for(int j=x1;j<=x2;j++)
				if(mat[j][y]==2)
					flag=true;
			if(!flag)
				ret+=solve(x1, y1, x2, y-1, 0)*solve(x1, y+1, x2, y2, 0);
		}
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &mat[i][j]);
	int ans=solve(0, 0, n-1, n-1, -1);
	printf("%d\n", ans==0?-1:ans);
	return 0;
}


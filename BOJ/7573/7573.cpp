// =====================================================================================
// 
//       Filename:  7573.cpp
//        Created:  2017년 03월 29일 00시 33분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, l, m;
pair<int, int> fish[100];
vector<int> x;
vector<int> y;
bool possi(int idx, int sx, int sy, int fx, int fy){
	return sx<=fish[idx].first&&fish[idx].first<=fx&&sy<=fish[idx].second&&fish[idx].second<=fy;
}
int main(){
	scanf("%d%d%d", &n, &l, &m);
	for(int i=0;i<m;i++){
		scanf("%d%d", &fish[i].first, &fish[i].second);
		x.push_back(fish[i].first);
		y.push_back(fish[i].second);
	}
	x.push_back(1);
	y.push_back(1);
	for(int i=1;i<l/2;i++){
		x.push_back(n-i);
		y.push_back(n-i);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	int ans=0;
	for(int i=0;i<x.size();i++)
		for(int j=0;j<y.size();j++){
			int nx=x[i];
			int ny=y[j];
			for(int w=1;w<l/2;w++){
				int h=l/2-w;
				int cnt=0;
				if(nx+w>n||ny+h>n)
					continue;
				for(int k=0;k<m;k++){
					if(possi(k, nx, ny, nx+w, ny+h))
						cnt++;
				}
				ans=max(ans, cnt);
			}
		}
	printf("%d\n", ans);
	return 0;
}


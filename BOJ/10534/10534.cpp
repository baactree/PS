// =====================================================================================
// 
//       Filename:  10534.cpp
//        Created:  2017년 08월 08일 21시 08분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Rect{
	int x, y, w, h;
};
int n;
Rect arr[50000];
int par[50000];
int w[50000];
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
int ans;
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	w[y]+=w[x];
	ans=max(ans, w[y]);
	par[x]=y;
}
int cnt[50000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d", &arr[i].x, &arr[i].y, &arr[i].w, &arr[i].h);
		par[i]=i;
		w[i]=arr[i].w*arr[i].h;
		ans=max(ans, w[i]);
	}
	for(int k=0;k<2;k++){
		vector<pair<pair<int, int>, pair<int, int> > > vec;
		for(int i=0;i<n;i++){
			vec.push_back({{arr[i].y, arr[i].x}, {0, i}});
			vec.push_back({{arr[i].y, arr[i].x+arr[i].w}, {1, i}});
			vec.push_back({{arr[i].y+arr[i].h, arr[i].x}, {0, i}});
			vec.push_back({{arr[i].y+arr[i].h, arr[i].x+arr[i].w}, {1, i}});
		}
		sort(vec.begin(), vec.end());
		queue<int> q;
		for(int i=0;i<vec.size();i++){
			int idx=vec[i].second.second;
			if(!vec[i].second.first){
				while(!q.empty()&&!cnt[q.front()])
					q.pop();
				if(!q.empty())
					merge(idx, q.front());
				q.push(idx);
				++cnt[idx];
			}
			else
				--cnt[idx];
		}
		for(int i=0;i<n;i++)
			swap(arr[i].x, arr[i].y), swap(arr[i].w, arr[i].h);
	}
	printf("%d\n", ans);
	return 0;
}


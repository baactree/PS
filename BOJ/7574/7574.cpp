// =====================================================================================
// 
//       Filename:  7574.cpp
//        Created:  2017년 08월 09일 21시 49분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, r, d;
pair<int, int> rect[100000];
int par[100000];
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
	par[x]=y;
}
int main(){
	scanf("%d%d", &n, &r);
	int st=-1;
	for(int i=0;i<n;i++){
		scanf("%d%d", &rect[i].first, &rect[i].second);
		if(rect[i].first==0&&rect[i].second==0)
			st=i;
		par[i]=i;
	}
	scanf("%d", &d);
	for(int k=0;k<2;k++){
		vector<pair<int, int> > vec;
		for(int i=0;i<n;i++){
			vec.push_back({rect[i].first, -i});
			vec.push_back({rect[i].first+r, i});
		}
		sort(vec.begin(), vec.end());
		set<pair<int, int> > us, ds;
		for(int i=0;i<vec.size();i++){
			int idx=vec[i].second;
			bool flag=false;
			if(idx<0){
				flag=true;
				idx=-idx;
			}
			int yh=rect[idx].second+r;
			int yl=rect[idx].second;
			if(flag){
				us.insert({yh, idx});
				ds.insert({yl, idx});
			}
			else{
				auto uit=ds.lower_bound({yh, 0});
				if(uit!=ds.end()&&(*uit).first<=yh+d)
					merge(idx, (*uit).second);
				auto dit=us.lower_bound({yl-d, 0});
				if(dit!=us.end()&&(*dit).first<=yl)
					merge(idx, (*dit).second);
				us.erase({yh, idx});
				ds.erase({yl, idx});
			}
		}
		for(int i=0;i<n;i++)
			swap(rect[i].first, rect[i].second);
	}
	int ans=0;
	for(int i=0;i<n;i++)
		if(find(st)==find(i))
			ans=max(ans, rect[i].first+rect[i].second+2*r);
	printf("%d\n", ans);
	return 0;
}


// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 08월 06일 22시 04분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<int, int> even[400005];
pair<int, int> odd[400005];
int arr[200005];
int n;
int sz;
const int inf=0x3f3f3f3f;
void update(int idx, pair<int, int> val, pair<int, int> *tree){
	idx+=sz;
	while(idx){
		tree[idx]=min(tree[idx], val);
		idx/=2;
	}
}
pair<int, int> query(int a, int b, pair<int, int> *tree){
	pair<int, int> ret={inf, inf};
	a+=sz;
	b+=sz;
	while(a<=b){
		if(a&1)
			ret=min(ret, tree[a++]);
		if(!(b&1))
			ret=min(ret, tree[b--]);
		a/=2;
		b/=2;
	}
	return ret;
}
int loc[200005];
void calc(int le, int ri, priority_queue<pair<pair<int, int>, pair<int, int> > > &pq){
	if(le>=ri+1)
		return;
	if(le&1){
		int left=le/2;
		int right=ri/2;
		auto l=query(left, right-1, odd);
		auto r=query(l.second/2+1, right, even);
		pq.push({{-l.first, -r.first}, {le, ri}});
		return;
	}	
	int left=le/2;
	int right=ri/2;
	auto l=query(left, right, even);
	auto r=query(l.second/2, right, odd);
	pq.push({{-l.first, -r.first}, {le, ri}});
}
int main(){
	memset(even, 0x3f, sizeof(even));
	memset(odd, 0x3f, sizeof(odd));
	scanf("%d", &n);
	sz=1;
	while(sz<n/2)sz*=2;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		arr[i]=x;
		loc[x]=i;
		int idx=i/2;
		if(i&1)
			update(idx, {x, i}, odd);		
		else
			update(idx, {x, i}, even);
	}
	vector<pair<int, int> > ans;
	priority_queue<pair<pair<int, int>, pair<int, int> > >pq;
	calc(0, n-1, pq);
	while(!pq.empty()){
		int a=-pq.top().first.first;
		int b=-pq.top().first.second;
		int le=pq.top().second.first;
		int ri=pq.top().second.second;
		pq.pop();
		ans.push_back({a, b});
		calc(le, loc[a]-1, pq);
		calc(loc[a]+1, loc[b]-1, pq);
		calc(loc[b]+1, ri, pq);
	}
	for(int i=0;i<ans.size();i++)
		printf("%d %d ", ans[i].first, ans[i].second);
	printf("\n");
	return 0;
}


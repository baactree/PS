// =====================================================================================
// 
//       Filename:  9345.cpp
//        Created:  2017년 05월 19일 00시 46분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<pair<int, int> > tree;
int sz;
const int inf=0x3f3f3f3f;
void update(int idx, int val){
	idx+=sz;
	tree[idx]={val, val};
	idx/=2;
	while(idx){
		tree[idx].first=max(tree[idx*2+1].first, tree[idx*2].first);
		tree[idx].second=min(tree[idx*2+1].second, tree[idx*2].second);
		idx/=2;
	}
}
pair<int, int> query(int a, int b){
	a+=sz;
	b+=sz;
	pair<int, int> ret={0, inf};
	while(a<=b){
		if(a&1){
			ret.first=max(ret.first, tree[a].first);
			ret.second=min(ret.second, tree[a].second);
			a++;
		}
		if(!(b&1)){
			ret.first=max(ret.first, tree[b].first);
			ret.second=min(ret.second, tree[b].second);
			b--;
		}
		a/=2;
		b/=2;
	}
	return ret;
}
int arr[100000];
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d", &n, &k);
		sz=1;
		while(sz<n)
			sz*=2;
		tree=vector<pair<int, int> > (sz*2+1, {0, inf});
		for(int i=0;i<n;i++){
			update(i, i);
			arr[i]=i;
		}
		for(int i=0;i<k;i++){
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			if(a==1){
				pair<int, int> q=query(b, d);
				if(q.first==d&&q.second==b)
					printf("YES\n");
				else 
					printf("NO\n");
			}
			else{
				swap(arr[b], arr[d]);
				update(b, arr[b]);
				update(d, arr[d]);
			}
		}
	}
	return 0;
}


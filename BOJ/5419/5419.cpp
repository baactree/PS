// =====================================================================================
// 
//       Filename:  5419.cpp
//        Created:  2017년 04월 21일 15시 44분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[75000];
int n;
int tree[75005];
void update(int idx){
	while(idx<75005){
		tree[idx]++;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	if(a.first==b.first)
		return a.second>b.second;
	return a.first<b.first;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d", &n);
		memset(tree, 0, sizeof(tree));
		vector<int> y;
		for(int i=0;i<n;i++){
			scanf("%d%d", &arr[i].first, &arr[i].second);
			y.push_back(arr[i].second);
		}
		sort(arr, arr+n, cmp);
		sort(y.begin(), y.end());
		y.erase(unique(y.begin(), y.end()), y.end());
		long long ans=0;
		for(int i=0;i<n;i++){
			int yidx=lower_bound(y.begin(), y.end(), arr[i].second)-y.begin()+1;
			int cnt=query(75000)-query(yidx-1);
			ans+=cnt;
			update(yidx);
		}
		printf("%lld\n", ans);
	}
	return 0;
}


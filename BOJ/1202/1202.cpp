// =====================================================================================
// 
//       Filename:  1202.cpp
//        Created:  2017년 03월 04일 20시 06분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> j[300000];
bool cmp(const pair<int, int>& a, const pair<int, int>& b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second>b.second;
}
multiset<int> s;
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d%d", &j[i].first, &j[i].second);
	for(int i=0;i<k;i++){
		int in;
		scanf("%d", &in);
		s.insert(in);
	}
	long long ans=0;
	sort(j, j+n, cmp);
	for(int i=0;i<n;i++){
		auto it = s.lower_bound(j[i].first);
		if(it!=s.end()){
			ans+=j[i].second;
			s.erase(it);
		}
	}
	printf("%lld\n", ans);
	return 0;
}


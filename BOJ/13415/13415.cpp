// =====================================================================================
// 
//       Filename:  13415.cpp
//        Created:  2017년 06월 16일 17시 14분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100005];
vector<pair<int, int> > q;
vector<pair<int, int> > rq;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		q.push_back({a, 1});
		q.push_back({b, 0});
	}
	reverse(q.begin(), q.end());
	int now=0;
	for(int i=0;i<q.size();i++){
		if(now<q[i].first){
			now=q[i].first;
			rq.push_back({q[i].first, q[i].second});
		}
	}
	reverse(rq.begin(), rq.end());
	rq.push_back({0, 0});
	int r=n-rq[0].first;
	vector<int> ans;
	for(int i=0;i<r;i++)
		ans.push_back(arr[n-i]);
	set<pair<int, int> > s;
	for(int i=1;i<=rq[0].first;i++)
		s.insert({arr[i], i});
	for(int i=0;i+1<rq.size();i++){
		int r=rq[i].first-rq[i+1].first;
		for(int j=0;j<r;j++){
			if(s.empty())
				break;
			if(rq[i].second){
				auto now=--s.end();
				ans.push_back((*now).first);
				s.erase(now);
			}
			else{
				auto now=s.begin();
				ans.push_back((*now).first);
				s.erase(now);
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}


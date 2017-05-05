// =====================================================================================
// 
//       Filename:  11997.cpp
//        Created:  2017년 05월 05일 02시 32분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k;
vector<vector<int> > arr;
vector<int> solve(int le, int ri){
	if(le==ri)
		return arr[le];
	int mid=(le+ri)/2;
	vector<int> left_ret=solve(le, mid);
	vector<int> right_ret=solve(mid+1, ri);
	vector<int> ret;
	priority_queue<pair<int, int> > pq;
	for(int i=0;i<right_ret.size();i++)
		pq.push({-(left_ret[0]+right_ret[i]), 0});
	for(int i=0;i<k;i++){
		ret.push_back(-pq.top().first);
		int now=-pq.top().first;
		int idx=-pq.top().second;
		pq.pop();
		if(idx+1<k)
			pq.push({-(now-left_ret[idx]+left_ret[idx+1]), -(idx+1)});
	}
	return ret;
}
int main(){
	while(scanf("%d", &k)!=EOF){
		arr=vector<vector<int> > (k, vector<int>(k));
		for(int i=0;i<k;i++)
			for(int j=0;j<k;j++)
				scanf("%d", &arr[i][j]);
		for(int i=0;i<k;i++)
			sort(arr[i].begin(), arr[i].end());
		vector<int> ans=solve(0, k-1);
		for(int i=0;i<ans.size();i++)
			printf("%d%s", ans[i], (i+1<ans.size()?" ":""));
		printf("\n");
	}
	return 0;
}


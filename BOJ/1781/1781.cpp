// =====================================================================================
// 
//       Filename:  1781.cpp
//        Created:  2017년 05월 02일 01시 38분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> d[200005];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		d[a].push_back(b);
	}
	int ans=0;
	priority_queue<int> pq;
	for(int i=n;i>=1;i--){
		for(int j=0;j<d[i].size();j++)
			pq.push(d[i][j]);
		if(!pq.empty()){
			ans+=pq.top();
			pq.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}


// =====================================================================================
// 
//       Filename:  13904.cpp
//        Created:  2017년 04월 23일 19시 42분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr[1001];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a].push_back(b);
	}
	int ans=0;
	priority_queue<int> pq;
	for(int i=1000;i>0;i--){
		for(int j=0;j<arr[i].size();j++)
			pq.push(arr[i][j]);
		if(!pq.empty()){
			int now=pq.top();
			pq.pop();
			ans+=now;
		}
	}
	printf("%d\n", ans);
	return 0;
}


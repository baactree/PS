// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 20일 19시 06분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;
int main(){
	scanf("%d", &n);
	while(n--){
		int a, b;
		scanf("%d.%d", &a, &b);
		int k=a*1000+b;
		if(pq.size()<7){
			pq.push(k);
		}
		else if(pq.top()>k){
			pq.pop();
			pq.push(k);
		}
	}
	vector<int> ans;
	while(!pq.empty()){
		int now=pq.top();
		pq.pop();
		ans.push_back(now);
	}
	reverse(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++){
		int a=ans[i]/1000;
		int b=ans[i]%1000;
		printf("%d.%03d\n", a, b);
	}
	return 0;
}


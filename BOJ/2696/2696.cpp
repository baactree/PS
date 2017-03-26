// =====================================================================================
// 
//       Filename:  2696.cpp
//        Created:  2017년 03월 26일 22시 40분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		priority_queue<int> le, ri;
		vector<int> ans;
		for(int i=0;i<n;i++){
			int in;
			scanf("%d", &in);
			if(ri.empty()||in<-ri.top())
				le.push(in);
			else
				ri.push(-in);

			if(le.size()>ri.size()+1){
				ri.push(-le.top());
				le.pop();
			}
			if(le.size()<ri.size()){
				le.push(-ri.top());
				ri.pop();
			}
			if(i%2==0)
				ans.push_back(le.top());
		}
		printf("%d\n", ans.size());
		for(int i=0;i<ans.size();i++){
			printf("%d ", ans[i]);
			if(i%10==9)
				printf("\n");
		}
		printf("\n");
	}
	return 0;
}


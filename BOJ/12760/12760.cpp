// =====================================================================================
// 
//       Filename:  12760.cpp
//        Created:  2017년 06월 08일 15시 29분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int score[100];
int n, m;
priority_queue<int> pq[100];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int in;
			scanf("%d", &in);
			pq[i].push(in);
		}
	for(int i=0;i<m;i++){
		vector<int> vec;
		int max_value=-1;
		for(int j=0;j<n;j++){
			int now=pq[j].top();
			pq[j].pop();
			if(now>max_value){
				vec.clear();
				vec.push_back(j);
				max_value=now;
			}
			else if(now==max_value)
				vec.push_back(j);
		}
		for(int j=0;j<vec.size();j++)
			score[vec[j]]++;
	}
	vector<int> ans;
	int max_value=-1;
	for(int i=0;i<n;i++){
		if(score[i]>max_value){
			max_value=score[i];
			ans.clear();
			ans.push_back(i+1);
		}
		else if(score[i]==max_value){
			ans.push_back(i+1);
		}
	}
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}


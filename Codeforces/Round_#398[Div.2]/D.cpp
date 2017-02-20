// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 02월 20일 22시 32분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int f[10000001];
priority_queue<pair<int, int> > pq;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<n;i++){
		int num;
		scanf("%d", &num);
		f[num]++;
	}
	for(int i=0;i<m;i++){
		int num;
		scanf("%d", &num);
		pq.push({-num, i+1});
	}
	for(int i=10000000;i>=0;i--){
		if(i==0){
			if(f[i]>k){
				printf("-1\n");
				return 0;
			}
		}
		if(f[i]>k){
			f[i-1]+=f[i]-k;
			f[i]-=k;
		}
	}
	vector<int> ans;
	for(int i=0;i<=10000000;i++){
		while(!pq.empty()&&-pq.top().first<i){
			pq.pop();
		}
		int num=k-f[i];
		while(!pq.empty()&&num--){
			ans.push_back(pq.top().second);
			pq.pop();
		}
	}
	printf("%d\n", ans.size());
	for(auto i:ans)
		printf("%d ", i);
	return 0;
}


// =====================================================================================
// 
//       Filename:  2143.cpp
//        Created:  2017년 05월 13일 22시 28분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
int a[1000];
int b[1000];
vector<long long> aa;
int main(){
	scanf("%d", &t);
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i=0;i<m;i++)
		scanf("%d", &b[i]);
	for(int i=0;i<n;i++){
		long long sum=0;
		for(int j=0;i+j<n;j++){
			sum+=a[i+j];
			aa.push_back(sum);
		}
	}
	sort(aa.begin(), aa.end());
	long long ans=0;
	for(int i=0;i<m;i++){
		long long sum=0;
		for(int j=0;i+j<m;j++){
			sum+=b[i+j];
			auto it=equal_range(aa.begin(), aa.end(), t-sum);
			ans+=it.second-it.first;
		}
	}
	printf("%lld\n", ans);
	return 0;
}


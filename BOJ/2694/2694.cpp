// =====================================================================================
// 
//       Filename:  2694.cpp
//        Created:  2017년 05월 12일 13시 58분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int m;
int arr[10000];
bool possi(long long x){
	long long sum=0;
	for(int i=0;i<m;i++){
		if(sum==x)
			sum=0;
		if(sum+arr[i]>x)
			return false;
		sum+=arr[i];
	}
	return true;
}
long long calc(vector<long long> &p){
	for(int i=0;i<p.size();i++){
		if(possi(p[i]))
			return p[i];
	}
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &m);
		long long sum=0;
		for(int i=0;i<m;i++){
			scanf("%d", &arr[i]);
			sum+=arr[i];
		}
		vector<long long> p;
		for(long long i=1;i*i<=sum;i++){
			if(sum%i==0){
				p.push_back(i);
				p.push_back(sum/i);
				if(i==sum/i)
					p.pop_back();
			}
		}
		sort(p.begin(), p.end());
		long long ans=calc(p);
		printf("%lld\n", ans);
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 02월 25일 22시 23분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100000];
long long sum[100001];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum[i+1]=sum[i]+arr[i];
	}
	vector<long long> temp;
	long long x=1;
	int cnt=0;
	while(abs(x)<=1e14&&cnt<50){
		temp.push_back(x);
		x*=k;
		cnt++;
	}
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	map<long long, int> m;
	long long ans=0;
	m[0]++;
	for(int i=1;i<=n;i++){
		for(int j=0;j<temp.size();j++){
			ans+=m[sum[i]-temp[j]];
		}
		m[sum[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}


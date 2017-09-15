// =====================================================================================
// 
//       Filename:  1450.cpp
//        Created:  2017년 09월 15일 19시 35분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, c;
int arr[30];
int main(){
	vector<ll> vec;
	scanf("%d%d", &n, &c);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int mid=n/2;
	for(int i=0;i<(1<<mid);i++){
		ll sum=0;
		for(int j=0;j<mid;j++)
			if(i&(1<<j))
				sum+=arr[j];
		vec.push_back(sum);
	}
	sort(vec.begin(), vec.end());
	int ans=0;
	for(int i=0;i<(1<<(n-mid));i++){
		ll sum=0;
		for(int j=mid;j<n;j++)
			if(i&(1<<(j-mid)))
				sum+=arr[j];
		int idx=upper_bound(vec.begin(), vec.end(), c-sum)-vec.begin();
		ans+=idx;
	}
	printf("%d\n", ans);
	return 0;
}


// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 29일 11시 37분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int n;
pair<pair<int, int> , int> arr[100005];
typedef long long ll;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	ll c=(ll)a.first.second*b.first.first+b.first.second;
	ll d=(ll)b.first.second*a.first.first+a.first.second;
	if(c==d)
		return a.second<b.second;
	return c<d;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d%d", &arr[i].first.first, &arr[i].first.second);
			arr[i].second=i+1;
		}
		sort(arr, arr+n, cmp);
		ll ans=0;
		for(int i=0;i<n;i++)
			ans+=(ll)(n-i)*(arr[i].second);
		printf("%lld\n", ans);
	}
	return 0;
}

// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 30일 21시 06분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> arr[100005];
typedef long long ll;
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
		arr[i].second*=-1;
	}
	sort(arr, arr+n);
	ll ans=0;
	for(int i=30;i>=0;i--){
		int nk=k&(~(1<<i));
		int g=0;
		ll t=0;
		for(int j=0;j<n;j++){
			if((g|arr[j].first)<=nk){
				g|=arr[j].first;
				t-=arr[j].second;
			}
		}
		ans=max(ans, t);
	}
	printf("%lld\n", ans);
	return 0;
}


// =====================================================================================
// 
//       Filename:  2258.cpp
//        Created:  2017년 05월 14일 17시 59분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> arr[100000];
bool cmp(pair<int, int> &a, pair<int, int> &b){
	if(a.second==b.second)
		return a.first>b.first;
	return a.second<b.second;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr+n, cmp);
	long long ans=0x3f3f3f3f3f3f3f3f;
	long long w=0;
	long long c=0;
	for(int i=0;i<n;i++){
		if(i!=0&&arr[i].second==arr[i-1].second)
			c+=arr[i].second;
		else
			c=arr[i].second;
		w+=arr[i].first;
		if(w>=m)
			ans=min(ans, c);
	}
	printf("%lld\n", ans==0x3f3f3f3f3f3f3f3f?-1:ans);
	return 0;
}


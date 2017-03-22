// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 03월 21일 20시 02분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[200000];
int m;
pair<int, int> arr2[200000];
bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second<b.second;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	scanf("%d", &m);
	for(int i=0;i<m;i++)
		scanf("%d%d", &arr2[i].first, &arr2[i].second);
	sort(arr, arr+n);
	sort(arr2, arr2+m, cmp);
	int ans=0;
	ans=max(ans, arr[n-1].first-arr2[0].second);
	sort(arr, arr+n, cmp);
	sort(arr2, arr2+m);
	ans=max(ans, arr2[m-1].first-arr[0].second);
	printf("%d\n", ans);
	return 0;
}


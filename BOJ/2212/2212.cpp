// =====================================================================================
// 
//       Filename:  2212.cpp
//        Created:  2017년 06월 12일 02시 48분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[10000];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int ans=arr[n-1]-arr[0];
	vector<int> diff;
	for(int i=1;i<n;i++)
		diff.push_back(arr[i]-arr[i-1]);
	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());
	for(int i=0;i<k-1&&i<diff.size();i++)
		ans-=diff[i];
	printf("%d\n", ans);
	return 0;
}


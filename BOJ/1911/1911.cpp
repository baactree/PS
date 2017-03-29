// =====================================================================================
// 
//       Filename:  1911.cpp
//        Created:  2017년 03월 29일 20시 06분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, l;
pair<int, int> arr[10000];
int main(){
	scanf("%d%d", &n, &l);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr+n);
	int covered=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(arr[i].second<=covered)
			continue;
		int start=max(arr[i].first, covered);
		double w=arr[i].second-start;
		int cnt = ceil(w/l);
		covered=start+cnt*l;
		ans+=cnt;
	}
	printf("%d\n", ans);
	return 0;
}


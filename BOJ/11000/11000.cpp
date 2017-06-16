// =====================================================================================
// 
//       Filename:  11000.cpp
//        Created:  2017년 06월 16일 17시 11분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > arr;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		arr.push_back({a, 1});
		arr.push_back({b, 0});
	}
	sort(arr.begin(), arr.end());
	int ans=0;
	int cnt=0;
	for(int i=0;i<arr.size();i++){
		if(!arr[i].second)
			cnt--;
		else
			cnt++;
		ans=max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}


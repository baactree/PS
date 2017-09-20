// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 09월 20일 19시 10분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[100];
int main(){
	scanf("%d", &n);
	vector<pair<int, int> > vec;
	for(int i=0;i<n;i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
		if(arr[i].second!=0)
			vec.push_back({arr[i].first*arr[i].second, arr[i].second-1});
	}
	int ans=0;
	for(int i=0;i<vec.size();i++){
		int now=vec[i].first;
		ans+=now;
	}
	printf("%d\n", ans);
	return 0;
}


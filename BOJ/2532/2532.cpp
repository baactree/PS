// =====================================================================================
// 
//       Filename:  2532.cpp
//        Created:  2017년 05월 01일 15시 01분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > arr;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	if(a.second==b.second)
		return a.first<b.first;
	return a.second>b.second;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		int c;
		scanf("%d%d%d", &c, &a, &b);
		arr.push_back({a, b});
	}
	sort(arr.begin(), arr.end(), cmp);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	vector<int> lis;
	for(int i=0;i<arr.size();i++){
		auto it=upper_bound(lis.begin(), lis.end(), arr[i].first);
		if(it==lis.end())
			lis.push_back(arr[i].first);
		else
			*it=arr[i].first;
	}
	printf("%d\n", lis.size());
	return 0;
}


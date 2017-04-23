// =====================================================================================
// 
//       Filename:  2381.cpp
//        Created:  2017년 04월 23일 16시 59분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> p, m;
pair<int, int> arr[50000];
int n;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	for(int i=0;i<n;i++){
		p.push_back(arr[i].first+arr[i].second);
		m.push_back(arr[i].first-arr[i].second);
	}
	int ans=max(*max_element(p.begin(), p.end())-*min_element(p.begin(), p.end()), *max_element(m.begin(), m.end())-*min_element(m.begin(), m.end()));
	printf("%d\n", ans);
	return 0;
}


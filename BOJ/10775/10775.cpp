// =====================================================================================
// 
//       Filename:  10775.cpp
//        Created:  2017년 06월 12일 15시 41분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int g, p;
int arr[100005];
int main(){
	scanf("%d%d", &g, &p);
	int ans=0;
	set<int> s;
	for(int i=1;i<=g;i++)
		s.insert(i);
	for(int i=0;i<p;i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0;i<p;i++){
		auto it=s.upper_bound(arr[i]);
		if(s.empty()||it==s.begin())
			break;
		s.erase(--it);
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}


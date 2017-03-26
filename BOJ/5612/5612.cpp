// =====================================================================================
// 
//       Filename:  5612.cpp
//        Created:  2017년 03월 26일 20시 44분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> arr[10000];
int solve(){
	int ret=m;
	for(int i=0;i<n;i++){
		m+=arr[i].first;
		m-=arr[i].second;
		ret=max(ret, m);
		if(m<0)
			return 0;
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	printf("%d\n", solve());
	return 0;
}


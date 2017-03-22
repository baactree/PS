// =====================================================================================
// 
//       Filename:  2517.cpp
//        Created:  2017년 03월 22일 18시 31분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[500000];
int cnt[500005];
int sq[5000];
int sz;
int ans[500000];
int query(int x){
	int idx=x/sz;
	int ret=0;
	for(int i=0;i<idx;i++)
		ret+=sq[i];
	for(int i=idx*sz;i<=x;i++)
		ret+=cnt[i];
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		arr[i]={in, i};
	}
	sort(arr, arr+n);
	sz=sqrt(n);
	for(int i=n-1;i>=0;i--){
		int t=query(arr[i].second);
		ans[arr[i].second]=t+1;
		cnt[arr[i].second]++;
		sq[arr[i].second/sz]++;
	}
	for(int i=0;i<n;i++)
		printf("%d\n", ans[i]);
	return 0;
}


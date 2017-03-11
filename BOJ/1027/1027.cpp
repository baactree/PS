// =====================================================================================
// 
//       Filename:  1027.cpp
//        Created:  2017년 03월 11일 19시 04분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[50];
typedef long long ll;
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
	ll temp=x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
	return temp;
}
bool possi(int a, int b){
	if(a>b)
		swap(a, b);
	for(int i=a+1;i<b;i++){
		if(ccw(a, arr[a], i, arr[i], b, arr[b])>0)
			continue;
		return false;
	}
	return true;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int ans=0;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(i==j)
				continue;
			if(possi(i, j))
				cnt++;
		}
		ans=max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}


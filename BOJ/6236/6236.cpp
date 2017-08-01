// =====================================================================================
// 
//       Filename:  6236.cpp
//        Created:  2017년 08월 01일 13시 48분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100005];
bool possi(int x){
	int cnt=0;
	int now=0;
	for(int i=0;i<n;i++){
		if(now<arr[i]){
			cnt++;
			now=x;
		}
		if(now<arr[i])
			return false;
		now-=arr[i];
	}
	return cnt<=m;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int le, ri, mid, ans;
	le=ans=0;
	ri=1e9;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%d\n", ans);
	return 0;
}


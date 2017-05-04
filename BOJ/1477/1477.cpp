// =====================================================================================
// 
//       Filename:  1477.cpp
//        Created:  2017년 05월 04일 22시 33분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int arr[1001];
bool possi(int x){
	int cnt=0;
	int now=0;
	for(int i=1;i<=l;i++){
		now++;
		if(now==x&&arr[i]==0){
			now=0;
			cnt++;
		}
		if(arr[i])
			now=0;
	}
	return cnt<=m;
}
int main(){
	scanf("%d%d%d", &n, &m, &l);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		arr[in]=1;
	}
	arr[0]=arr[l]=1;
	int le, ri, mid, ans;
	le=1;
	ri=l;
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


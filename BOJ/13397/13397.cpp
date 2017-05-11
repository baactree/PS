// =====================================================================================
// 
//       Filename:  13397.cpp
//        Created:  2017년 05월 11일 18시 45분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[5000];
bool possi(int x){
	int cnt=1;
	int min_value, max_value;
	min_value=0x3f3f3f3f;
	max_value=-0x3f3f3f3f;
	for(int i=0;i<n;i++){
		min_value=min(min_value, arr[i]);
		max_value=max(max_value, arr[i]);
		if(max_value-min_value>x){
			cnt++;
			min_value=arr[i];
			max_value=arr[i];
		}
	}
	return cnt<=m;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int le, ri, mid, ans;
	le=0;
	ri=20000;
	ans=-1;
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


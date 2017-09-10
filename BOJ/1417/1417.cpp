// =====================================================================================
// 
//       Filename:  1417.cpp
//        Created:  2017년 09월 10일 18시 52분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000];
bool possi(int x){
	int d=x-arr[0];
	int s=0;
	for(int i=1;i<n;i++){
		if(arr[i]>=x){
			s+=arr[i]-x+1;
		}
	}
	return s<=d;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int s=0;
	for(int i=1;i<n;i++)
		s+=arr[i];
	int le, ri, mid, ans;
	le=arr[0];
	ri=s+arr[0];
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
	printf("%d\n", ans-arr[0]);
	return 0;
}


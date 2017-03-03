// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 02월 20일 21시 08분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long ts, tf, t;
int n;
long long arr[100000];
long long fi[100000];
int main(){
	scanf("%lld%lld%lld", &ts, &tf, &t);
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	for(int i=0;i<n&&ts<tf;i++){
		if(arr[i]<=ts){
			fi[i]=ts;
			ts+=t;
		}
		else{
			printf("%lld\n", ts);
			return 0;
		}
	}
	if(ts+t<=tf){
		printf("%lld\n", ts);
		return 0;
	}
	long long dist=0x3f3f3f3f3f3f3f3f;
	long long ans=0;
	for(int i=0;i<n;i++){
		if(i!=0&&arr[i]==arr[i-1])
			continue;
		if(arr[i]!=0){
			long long now=abs(fi[i]-arr[i]+1);
			if(dist>now){
				dist=now;
				ans=arr[i]-1;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}


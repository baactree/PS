// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 05월 04일 10시 39분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[100000];
long long g[100000];
long long gcd(long long a, long long b){
	return b?gcd(b, a%b):a;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	int ans=0;
	int now=0;
	while(now<n){
		if(now==0){
			g[now]=arr[now];
			now++;
			continue;
		}
		long long ng=gcd(arr[now], g[now-1]);
		if(ng==1||ng==-1){
			long long temp=arr[now-1];
			arr[now-1]-=arr[now];
			arr[now]+=temp;
			now--;
			ans++;
		}
		else{
			g[now]=ng;
			now++;
		}
	}
	printf("YES\n%d\n", ans);
	return 0;
}


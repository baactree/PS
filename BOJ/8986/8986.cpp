// =====================================================================================
// 
//       Filename:  8986.cpp
//        Created:  2017년 04월 10일 10시 38분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
typedef long long ll;
ll f(int x){
	ll ret=0;
	for(ll i=0;i<n;i++){
		ret+=abs(i*x-arr[i]);
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	ll ans=0x3f3f3f3f3f3f3f3f;
	int le, ri;
	le=0;ri=1e9/n+100;
	while(le<=ri){
		int a=(le*2+ri)/3;
		int b=(le+ri*2)/3;
		if(f(a)>=f(b)){
			ans=min(ans, f(a));
			le=a+1;
		}
		else{
			ans=min(ans, f(b));
			ri=b-1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}


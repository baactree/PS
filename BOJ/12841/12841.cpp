// =====================================================================================
// 
//       Filename:  12841.cpp
//        Created:  2017년 06월 15일 16시 42분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int c[100005];
long long l[100005];
long long r[100005];
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &c[i]);
	for(int i=1;i<n;i++){
		scanf("%lld", &l[i]);
		l[i]+=l[i-1];
	}
	for(int i=1;i<n;i++){
		scanf("%lld", &r[i]);
		r[i]+=r[i-1];
	}
	long long min_value=0x3f3f3f3f3f3f3f3f;
	int idx=0;
	for(int i=1;i<=n;i++){
		long long now=c[i]+l[i-1]+r[n-1]-r[i-1];
		if(min_value>now){
			min_value=now;
			idx=i;
		}
	}
	printf("%d %lld\n", idx, min_value);
	return 0;
}


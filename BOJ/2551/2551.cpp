// =====================================================================================
// 
//       Filename:  2551.cpp
//        Created:  2017년 06월 06일 17시 05분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[10005];
long long linf=0x3f3f3f3f3f3f3f3f;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		cnt[in]++;
	}
	int ans1=0;
	int ans2=0;
	long long min_value1=linf;
	long long min_value2=linf;
	for(int i=1;i<=10000;i++){
		long long sum1=0;
		long long sum2=0;
		for(int j=1;j<=10000;j++){
			sum1+=(long long)cnt[j]*(abs(i-j));
			sum2+=(long long)cnt[j]*(abs(i-j))*(abs(i-j));
		}
		if(sum1<min_value1){
			min_value1=sum1;
			ans1=i;
		}
		if(sum2<min_value2){
			min_value2=sum2;
			ans2=i;
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}


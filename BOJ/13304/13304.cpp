// =====================================================================================
// 
//       Filename:  13304.cpp
//        Created:  2017년 05월 03일 14시 14분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int sum[5];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(b<3){
			sum[0]++;
		}
		else if(b<5){
			if(a)
				sum[1]++;
			else
				sum[2]++;
		}
		else{
			if(a)
				sum[3]++;
			else
				sum[4]++;
		}
	}
	int ans=0;
	for(int i=0;i<5;i++)
		ans+=(sum[i]+k-1)/k;
	printf("%d\n", ans);
	return 0;
}


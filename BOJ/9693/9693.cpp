// =====================================================================================
// 
//       Filename:  9693.cpp
//        Created:  2017년 09월 10일 18시 35분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int ans[1000005];
int main(){
	int a, b;
	a=b=0;
	for(int i=1;i<=1000000;i++){
		int k=i;
		while(k%2==0){
			a++;
			k/=2;
		}
		k=i;
		while(k%5==0){
			b++;
			k/=5;
		}
		ans[i]=min(a, b);
	}
	int n;
	int tc=0;
	while(true){
		scanf("%d", &n);
		if(n==0)
			break;
		printf("Case #%d: %d\n", ++tc, ans[n]);
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  1052.cpp
//        Created:  2017년 04월 23일 19시 22분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int main(){
	scanf("%d%d", &n, &k);
	int ans=0;
	while(k&&n!=0){
		if(k==1){
			int p=1;
			while(p<n)
				p*=2;
			ans+=p-n;
		}
		else{
			int p=1;
			while(p*2<n)
				p*=2;
			n-=p;
		}
		k--;
	}
	printf("%d\n", ans);
	return 0;
}


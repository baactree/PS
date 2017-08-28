// =====================================================================================
// 
//       Filename:  2737.cpp
//        Created:  2017년 08월 28일 23시 33분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int n;
		scanf("%d", &n);
		int ans=0;
		for(long long i=2;i*(i+1)/2<=n;i++){
			if(i&1){
				if(n%i==0&&n/i-i/2>=1)
					ans++;
			}
			else{
				if((n-i/2)%i==0&&(n-i/2)/i-i/2+1>=1)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}


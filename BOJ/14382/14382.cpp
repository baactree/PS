// =====================================================================================
// 
//       Filename:  14382.cpp
//        Created:  2017년 05월 27일 17시 16분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int tc=1;tc<=testcase;tc++){
		scanf("%d", &n);
		if(n==0){
			printf("Case #%d: INSOMNIA\n", tc);
			continue;
		}
		int t=n;
		int now=0;
		int goal=(1<<10)-1;
		while(true){
			int temp=n;
			while(temp){
				int p=temp%10;
				now|=(1<<p);
				temp/=10;
			}
			if(now==goal)
				break;
			n+=t;
		}
		printf("Case #%d: %d\n", tc, n);
	}
	return 0;
}


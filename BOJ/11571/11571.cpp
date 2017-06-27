// =====================================================================================
// 
//       Filename:  11571.cpp
//        Created:  2017년 06월 27일 15시 09분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int trip[1200];
char ans[2000];
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d.", a/b);
		a%=b;
		a*=10;
		memset(trip, -1, sizeof(trip));
		int idx=0;
		while(true){
			if(a==0){
				ans[idx]=0;
				printf("%s(0)\n", ans);
				break;
			}
			if(trip[a/10]!=-1){
				int t=trip[a/10];
				for(int i=0;i<t;i++)
					printf("%c", ans[i]);
				printf("(");
				for(int i=t;i<idx;i++)
					printf("%c", ans[i]);
				printf(")\n");
				break;
			}
			trip[a/10]=idx;
			ans[idx++]=(char)(a/b+'0');
			a%=b;
			a*=10;
		}
	}
	return 0;
}


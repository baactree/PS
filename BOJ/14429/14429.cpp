// =====================================================================================
// 
//       Filename:  14429.cpp
//        Created:  2017년 06월 02일 12시 49분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
	int testcase;
	scanf("%d", &testcase);
	int ans=0x3f3f3f3f;
	int idx=0;
	for(int tc=1;tc<=testcase;tc++){	
		scanf("%d%d", &n, &m);
		int r=(n-1)%(m+1);
		int now=((n-r-1)/(m+1)+1)*2;
		if(now<ans){
			ans=now;
			idx=tc;
		}
	}
	printf("%d %d\n", idx, ans);
	return 0;
}


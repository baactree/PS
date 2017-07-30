// =====================================================================================
// 
//       Filename:  Extreme_Number.cpp
//        Created:  2017년 06월 29일 22시 36분 45초
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
	for(int tc=1;tc<=testcase;tc++){
		int k;
		scanf("%d", &k);
		k++;
		stack<int> st;
		while(k){
			st.push(k&1);
			k/=2;
		}
		st.pop();
		printf("Case #%d\n", tc);
		while(!st.empty()){
			printf("%d", st.top()?7:4);
			st.pop();
		}
		printf("\n");
	}
	return 0;
}


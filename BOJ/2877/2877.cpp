// =====================================================================================
// 
//       Filename:  2877.cpp
//        Created:  2017년 04월 02일 14시 10분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k;
int main(){
	scanf("%d", &k);
	k++;
	stack<int> st;
	while(k){
		st.push(k&1);
		k/=2;
	}
	st.pop();
	while(!st.empty()){
		if(st.top())
			printf("7");
		else
			printf("4");
		st.pop();
	}
	printf("\n");
	return 0;
}


// =====================================================================================
// 
//       Filename:  14491.cpp
//        Created:  2017년 05월 04일 22시 59분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	stack<int> st;
	while(t){
		st.push(t%9);
		t/=9;
	}
	while(!st.empty()){
		printf("%d", st.top());
		st.pop();
	}
	return 0;
}


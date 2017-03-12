// =====================================================================================
// 
//       Filename:  11179.cpp
//        Created:  2017년 03월 12일 18시 05분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	stack<int> st;
	int n;
	scanf("%d", &n);
	while(n){
		st.push(n%2);
		n/=2;
	}
	int ans=0;
	int r=1;
	while(!st.empty()){
		int now=st.top();
		st.pop();
		ans+=now*r;
		r*=2;
	}
	printf("%d\n", ans);
	return 0;
}


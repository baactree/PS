// =====================================================================================
// 
//       Filename:  12789.cpp
//        Created:  2017년 03월 13일 23시 09분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> st;
int main(){
	scanf("%d", &n);
	int now=1;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		if(in==now)
			now++;
		else if(in>now){
			st.push(in);
		}
		while(!st.empty()&&st.top()==now){
			st.pop();
			now++;
		}
	}
	if(now==n+1)
		printf("Nice\n");
	else
		printf("Sad\n");
	return 0;
}


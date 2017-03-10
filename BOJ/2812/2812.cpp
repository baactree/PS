// =====================================================================================
// 
//       Filename:  2812.cpp
//        Created:  2017년 03월 10일 19시 31분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
string num;
int main(){
	cin>>n>>k>>num;
	stack<int> st;
	for(int i=0;i<num.size();i++){
		while(k!=0&&!st.empty()&&st.top()<num[i]){
			k--;
			st.pop();
		}
		st.push(num[i]);
	}
	while(k!=0&&!st.empty()){
		k--;
		st.pop();
	}
	stack<int> ans;
	while(!st.empty()){
		ans.push(st.top());
		st.pop();
	}
	while(!ans.empty()){
		printf("%c", ans.top());
		ans.pop();
	}
	return 0;
}


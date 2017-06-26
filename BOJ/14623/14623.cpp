// =====================================================================================
// 
//       Filename:  14623.cpp
//        Created:  2017년 06월 26일 17시 22분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a, b;
long long int p, q, w;
int main(){
	cin>>a>>b;
	int r=1;
	for(int i=a.size()-1;i>=0;i--){
		p+=(a[i]-'0')*r;
		r*=2;
	}
	r=1;
	for(int i=b.size()-1;i>=0;i--){
		q+=(b[i]-'0')*r;
		r*=2;
	}
	w=p*q;
	stack<int> st;
	while(w){
		st.push(w&1);
		w/=2;
	}
	while(!st.empty()){
		printf("%d", st.top());
		st.pop();
	}
	return 0;
}


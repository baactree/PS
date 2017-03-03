// =====================================================================================
// 
//       Filename:  2986.cpp
//        Created:  2017년 02월 20일 19시 49분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	queue<int> st;
	for(int i=2;i*i<=N;i++){
		if(N%i==0)
			st.push(i);
	}
	if(st.empty()){
		printf("%d\n", N-1);
		return 0;
	}
	printf("%d\n", N-(N/st.front()));
	return 0;
}


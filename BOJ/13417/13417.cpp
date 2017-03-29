// =====================================================================================
// 
//       Filename:  13417.cpp
//        Created:  2017년 03월 29일 20시 40분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		deque<char> dq;
		for(int i=0;i<n;i++){
			char in[2];
			scanf("%s", in);
			if(dq.empty()||dq.front()<in[0])
				dq.push_back(in[0]);
			else
				dq.push_front(in[0]);
		}
		for(int i=0;i<dq.size();i++)
			printf("%c", dq[i]);
		printf("\n");
	}
	return 0;
}


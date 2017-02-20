// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 02월 20일 20시 59분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100000];
int main(){
	scanf("%d", &N);
	int now=N;
	priority_queue<int> pq;
	for(int i=0;i<N;i++){
		int n;
		scanf("%d", &n);
		pq.push(n);
		while(pq.top()==now){
			printf("%d ", pq.top());
			pq.pop();
			now--;
		}
		printf("\n");
	}
	return 0;
}


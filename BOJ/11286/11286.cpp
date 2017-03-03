// =====================================================================================
// 
//       Filename:  11286.cpp
//        Created:  2017년 02월 22일 15시 39분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, bool> > pq;
int n;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		if(in==0){
			if(pq.empty())
				printf("0\n");
			else{
				int now=-pq.top().first;
				int sign=pq.top().second;
				pq.pop();
				printf("%s%d\n", sign?"-":"", now);
			}
		}
		else{
			pq.push({-abs(in), in<0});
		}
	}
	return 0;
}


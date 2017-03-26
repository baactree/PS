// =====================================================================================
// 
//       Filename:  9934.cpp
//        Created:  2017년 03월 26일 20시 47분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k;
int arr[1<<10];
int main(){
	scanf("%d", &k);
	for(int i=0;i<(1<<k)-1;i++)
		scanf("%d", &arr[i]);
	queue<pair<int, int> > q;
	q.push({0, (1<<k)-2});
	while(!q.empty()){
		int sz=q.size();
		for(int i=0;i<sz;i++){
			int le=q.front().first;
			int ri=q.front().second;
			q.pop();
			int mid=(le+ri)/2;
			printf("%d ", arr[mid]);
			if(le==ri)
				continue;
			q.push({le, mid-1});
			q.push({mid+1, ri});
		}
		printf("\n");
	}
	return 0;
}


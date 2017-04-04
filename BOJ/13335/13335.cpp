// =====================================================================================
// 
//       Filename:  13335.cpp
//        Created:  2017년 04월 05일 01시 35분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, w, l;
int arr[1000];
int main(){
	scanf("%d%d%d", &n, &w, &l);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int idx=0;
	int ans=0;
	int noww=0;
	queue<pair<int, int> > q;
	while(true){
		if(!q.empty()&&ans-q.front().first==w){
			noww-=arr[q.front().second];
			if(q.front().second==n-1){
				printf("%d\n", ans+1);
				return 0;
			}
			q.pop();
		}
		if(arr[idx]+noww<=l){
			noww+=arr[idx];
			q.push({ans, idx});
			idx++;
		}
		ans++;
	}
	return 0;
}


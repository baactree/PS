// =====================================================================================
// 
//       Filename:  8891.cpp
//        Created:  2017년 03월 21일 18시 29분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int a, b;
		scanf("%d%d", &a, &b);
		int ax, ay, bx, by;
		int cnt=1;
		int sum=1;
		while(sum<=a){
			sum+=cnt;
			cnt++;
		}
		cnt--;
		sum-=cnt;
		ax=cnt-(a-sum);
		ay=a-sum+1;
		cnt=1;
		sum=1;
		while(sum<=b){
			sum+=cnt;
			cnt++;
		}
		cnt--;
		sum-=cnt;
		bx=cnt-(b-sum);
		by=b-sum+1;
		int cx=ax+bx;
		int cy=ay+by;
		int level=cx+cy-2;
		cnt=1;
		sum=1;
		for(int i=0;i<level;i++)
			sum+=cnt++;
		cy--;
		printf("%d\n", sum+cy);
	}
	return 0;
}


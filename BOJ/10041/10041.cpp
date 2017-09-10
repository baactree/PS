// =====================================================================================
// 
//       Filename:  10041.cpp
//        Created:  2017년 09월 10일 19시 16분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int w, h, n;
int main(){
	scanf("%d%d%d", &w, &h, &n);
	int x, y;
	scanf("%d%d", &x, &y);
	int ans=0;
	for(int i=1;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(x<a&&y<b){
			int k=min(a-x, b-y);
			ans-=k;
		}
		else if(a<x&&b<y){
			int k=min(x-a, y-b);
			ans-=k;
		}
		ans+=abs(a-x)+abs(b-y);
		x=a;
		y=b;
	}
	printf("%d\n", ans);
	return 0;
}


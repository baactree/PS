// =====================================================================================
// 
//       Filename:  4083.cpp
//        Created:  2017년 04월 23일 22시 26분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		long long a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if(a==0&&a==b&&b==c&&c==d)
			break;
		int cnt=0;
		while(true){
			if(a==b&&b==c&&c==d)
				break;
			long long na=abs(a-b);
			long long nb=abs(b-c);
			long long nc=abs(c-d);
			long long nd=abs(d-a);
			cnt++;
			a=na;
			b=nb;
			c=nc;
			d=nd;
		}
		printf("%d\n", cnt);
	}
	return 0;
}


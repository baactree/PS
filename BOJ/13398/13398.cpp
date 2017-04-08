// =====================================================================================
// 
//       Filename:  13398.cpp
//        Created:  2017년 04월 07일 15시 42분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b;
int n;
int main(){
	scanf("%d", &n);
	a=b=-0x3f3f3f3f;
	int ans=-0x3f3f3f3f;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		b=max(b+in, a);
		a=max(in, a+in);
		ans=max(ans, max(a, b));
	}
	printf("%d\n", ans);
	return 0;
}


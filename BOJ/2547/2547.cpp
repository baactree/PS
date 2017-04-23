// =====================================================================================
// 
//       Filename:  2547.cpp
//        Created:  2017년 04월 21일 16시 21분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d", &n);
		long long mod=0;
		for(int i=0;i<n;i++){
			long long in;
			scanf("%lld", &in);
			mod+=in;
			mod%=n;
		}
		printf("%s\n", mod?"NO":"YES");
	}
	return 0;
}


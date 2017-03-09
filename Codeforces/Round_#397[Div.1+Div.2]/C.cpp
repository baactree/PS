// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 03월 09일 15시 46분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long k, a, b;
long long bw, aw;
int main(){
	scanf("%lld%lld%lld", &k, &a, &b);
	aw=a/k;
	bw=b/k;
	a=a%k;
	b=b%k;
	bool flag=false;
	if(a>bw*(k-1))
		flag=true;
	if(b>aw*(k-1))
		flag=true;
	if(aw+bw==0||flag)
		printf("-1\n");
	else
		printf("%lld\n", aw+bw);
	return 0;
}

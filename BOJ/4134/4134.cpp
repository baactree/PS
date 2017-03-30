// =====================================================================================
// 
//       Filename:  4134.cpp
//        Created:  2017년 03월 31일 03시 00분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool possi(long long x){
	if(x==1)
		return false;
	if(x==2)
		return true;
	if(x%2==0)
		return false;
	for(long long i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		long long n;
		scanf("%lld", &n);
		while(!possi(n))
			n++;
		printf("%lld\n", n);
	}
	return 0;
}


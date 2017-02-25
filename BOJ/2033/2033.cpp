// =====================================================================================
// 
//       Filename:  2033.cpp
//        Created:  2017년 02월 25일 20시 33분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long n;
long long x;
int main(){
	scanf("%lld", &n);
	x=10;
	while(n>x){
		long long k=x/10;
		int	temp=(n/k)%10;
		if(temp<5){
			n-=temp*k;
		}
		else{
			n-=temp*k;
			n+=k*10;
		}
		x*=10;
	}
	printf("%lld\n", n);
	return 0;
}


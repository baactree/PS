// =====================================================================================
// 
//       Filename:  11947.cpp
//        Created:  2017년 02월 04일 20시 42분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int main(){
	int Case;
	scanf("%d", &Case);
	while(Case--){
		int N;
		scanf("%d", &N);
		string now=to_string(N);
		long long num=5;
		for(int i=1;i<now.size();i++)
			num*=10;
		if(N<num){
			for(int i=0;i<now.size();i++)
				now[i]='9'-now[i]+'0';
			num=stoll(now);
			printf("%lld\n", (long long)N*num);
		}
		else{
			printf("%lld\n", (long long)num*(num-1));
		}
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  1300.cpp
//        Created:  2017년 03월 17일 19시 46분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool possi(long long x){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=min((long long)n*i, x)/i;
	}
	return cnt>=k;
}
int main(){
	scanf("%lld%lld", &n, &k);
	if(k>1e9)
		while(true);
	long long le, ri, mid, x;
	le=1;
	ri=n*n;
	while(ri>=le){
		mid=(le+ri)/2;
		if(possi(mid)){
			x=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%lld\n", x);
	return 0;
}


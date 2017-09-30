// =====================================================================================
// 
//       Filename:  14715.cpp
//        Created:  2017년 09월 30일 16시 30분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cache[1000005];
int solve(int idx){
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	for(int i=1;i*i<=idx;i++){
		if(idx%i==0){
			if(i>1&&idx/i>1)
				ret=min(ret, max(solve(i), solve(idx/i))+1);
		}
	}
	if(ret==0x3f3f3f3f)
		ret=0;
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	int k;
	scanf("%d", &k);
	printf("%d\n", solve(k));
	return 0;
}


// =====================================================================================
// 
//       Filename:  2079.cpp
//        Created:  2017년 05월 08일 18시 31분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char str[2006];
int len;
int cache[2005];
bool possi(int le, int ri){
	while(le<=ri){
		if(str[le]!=str[ri])
			return false;
		le++;
		ri--;
	}
	return true;
}
int solve(int idx){
	if(idx==len)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	for(int i=idx;i<len;i++)
		if(possi(idx, i))
			ret=min(ret, solve(i+1)+1);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%s", &str);
	len=strlen(str);
	printf("%d\n", solve(0));
	return 0;
}


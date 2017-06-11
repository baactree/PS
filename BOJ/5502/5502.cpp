// =====================================================================================
// 
//       Filename:  5502.cpp
//        Created:  2017년 06월 12일 03시 10분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char str[5005];
const int inf=5005;
short cache[5005][5005];
short solve(int le, int ri){
	if(le==-1)
		return n-ri;
	if(ri==n)
		return le+1;
	short &ret=cache[le][ri];
	if(ret!=-1)
		return ret;
	ret=inf;
	if(str[le]==str[ri])
		ret=min((int)ret, (int)solve(le-1, ri+1));
	else{
		ret=min((int)ret, solve(le-1, ri)+1);
		ret=min((int)ret, solve(le, ri+1)+1);
	}
	return ret;
}
int main(){
	scanf("%d%s", &n, str);
	int ans=inf;
	memset(cache, -1, sizeof(cache));
	for(int i=0;i<n;i++){
		ans=min(ans, (int)solve(i, i));
		if(i+1<n&&str[i]==str[i+1])
			ans=min(ans, (int)solve(i, i+1));
	}
	printf("%d\n", ans);
	return 0;
}


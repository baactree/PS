// =====================================================================================
// 
//       Filename:  1535.cpp
//        Created:  2017년 04월 04일 17시 20분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int l[20];
int j[20];
int cache[1<<20];
int solve(int h, int state){
	if(h>=100)
		return -0x3f3f3f3f;
	int &ret=cache[state];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<n;i++){
		if(!(state&(1<<i))){
			ret=max(ret,solve(h+l[i], state|(1<<i))+j[i] );
		}
	}
	return ret;
}	
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &l[i]);
	for(int i=0;i<n;i++)
		scanf("%d", &j[i]);
	printf("%d\n", solve(0, 0));
	return 0;
}


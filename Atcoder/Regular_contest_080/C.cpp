// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 08월 06일 21시 38분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[3];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		if(x%4==0)
			cnt[2]++;
		else if(x%2==0)
			cnt[1]++;
		else
			cnt[0]++;
	}
	if(cnt[1]!=0)
		printf("%s\n", cnt[2]<cnt[0]?"No":"Yes");
	else
		printf("%s\n", cnt[2]<(cnt[0]-1)?"No":"Yes");
	return 0;
}


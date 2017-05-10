// =====================================================================================
// 
//       Filename:  13410.cpp
//        Created:  2017년 05월 05일 11시 04분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int ans=0;
	for(int i=1;i<=k;i++){
		string temp=to_string(n*i);
		reverse(temp.begin(), temp.end());
		int now=stoi(temp);
		ans=max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}


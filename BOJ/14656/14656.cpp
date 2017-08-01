// =====================================================================================
// 
//       Filename:  14656.cpp
//        Created:  2017년 07월 31일 17시 04분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int in;
		scanf("%d", &in);
		if(in!=i)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}


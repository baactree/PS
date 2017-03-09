// =====================================================================================
// 
//       Filename:  7894.cpp
//        Created:  2017년 03월 09일 20시 42분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int m;
		double ans=1;
		scanf("%d", &m);
		for(int i=1;i<=m;i++){
			ans+=log10(i);
		}
		printf("%d\n", (int)ans);
	}
	return 0;
}


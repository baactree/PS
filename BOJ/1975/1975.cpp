// =====================================================================================
// 
//       Filename:  1975.cpp
//        Created:  2017년 03월 27일 22시 50분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		int ans=0;
		for(int i=2;i<=n;i++){
			int k=n;
			while(k%i==0){
				ans++;
				k/=i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}


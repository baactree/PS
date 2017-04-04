// =====================================================================================
// 
//       Filename:  2725.cpp
//        Created:  2017년 04월 04일 17시 26분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int ans[1001];
bool used[1001][1001];
int gcd(int a, int b){
	return b?gcd(b, a%b):a;
}
int main(){
	ans[0]=0;
	ans[1]=3;
	for(int i=2;i<=1000;i++){
		int cnt=0;
		for(int j=1;j<i;j++){
			int g=gcd(i, j);
			if(!used[i/g][j/g]){
				cnt++;
				used[i/g][j/g]=true;
			}
		}
		ans[i]=ans[i-1]+cnt*2;
	}
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}


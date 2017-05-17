// =====================================================================================
// 
//       Filename:  14568.cpp
//        Created:  2017년 05월 15일 00시 47분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(i+j+k==n&&i>=j+2&&k%2==0)
					ans++;
			}
	printf("%d\n", ans);
	return 0;
}


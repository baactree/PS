// =====================================================================================
// 
//       Filename:  1773.cpp
//        Created:  2017-04-12 ¿ÀÈÄ 3:24:32
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, c;
int arr[100];
int main(){
	scanf("%d%d", &n, &c);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int ans=0;
	for(int day=1;day<=c;day++){
		for(int i=0;i<n;i++)
			if(day%arr[i]==0){
				ans++;
				break;
			}
	}
	printf("%d\n", ans);
	return 0;
}


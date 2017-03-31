// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 03월 31일 16시 10분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
bool arr[100001];
int main(){
	scanf("%d", &n);
	int ans=0;
	int now=0;
	for(int i=0;i<2*n;i++){
		int in;
		scanf("%d", &in);
		if(arr[in]){
			arr[in]=false;
			now--;
		}
		else{
			arr[in]=true;
			now++;
		}
		ans=max(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}

// =====================================================================================
// 
//       Filename:  9358.cpp
//        Created:  2017년 04월 28일 12시 46분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[100];
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%lld", &arr[i]);
		while(n!=2){
			for(int i=0;i<(n+1)/2;i++)
				arr[i]+=arr[n-1-i];
			n=(n+1)/2;
		}
		printf("Case #%d: %s\n", tc, arr[0]>arr[1]?"Alice":"Bob");
			
	}
	return 0;
}


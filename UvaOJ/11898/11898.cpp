// =====================================================================================
// 
//       Filename:  11898.cpp
//        Created:  2017년 05월 03일 19시 47분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		int n;
		scanf("%d", &n);
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		int q;
		scanf("%d", &q);
		while(q--){
			int a, b;
			scanf("%d%d", &a, &b);
			if(b-a+1>=10000){
				printf("0\n");
				continue;
			}
			a--;b--;
			vector<int> now;
			for(int i=a;i<=b;i++)
				now.push_back(arr[i]);
			sort(now.begin(), now.end());
			int ans=0x3f3f3f3f;
			for(int i=0;i+1<now.size();i++)
				ans=min(ans, now[i+1]-now[i]);
			printf("%d\n", ans);
		}
	}
	return 0;
}


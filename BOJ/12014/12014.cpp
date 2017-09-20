// =====================================================================================
// 
//       Filename:  12014.cpp
//        Created:  2017년 09월 19일 22시 12분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int tc=1;tc<=testcase;tc++){
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> lis;
		for(int i=0;i<n;i++){
			int x;
			scanf("%d", &x);
			auto it=lower_bound(lis.begin(), lis.end(), x);
			if(it==lis.end())
				lis.push_back(x);
			else
				*it=x;
		}
		printf("Case #%d\n%d\n", tc, lis.size()>=k);
	}
	return 0;
}


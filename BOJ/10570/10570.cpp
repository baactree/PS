// =====================================================================================
// 
//       Filename:  10570.cpp
//        Created:  2017년 05월 08일 17시 19분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cnt[1001];
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		int n;
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<n;i++){
			int in;
			scanf("%d", &in);
			cnt[in]++;
		}
		int max_value=-1;
		int idx;
		for(int i=1;i<=1000;i++)
			if(max_value<cnt[i]){
				max_value=cnt[i];
				idx=i;
			}
		printf("%d\n", idx);
	}
	return 0;
}


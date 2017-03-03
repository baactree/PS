// =====================================================================================
// 
//       Filename:  1365.cpp
//        Created:  2017년 02월 21일 15시 16분 04초
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
	vector<int> lis;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d", &num);
		vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), num);
		if(it==lis.end())
			lis.push_back(num);
		else
			*it = num;
	}
	printf("%d\n", n-lis.size());
	return 0;
}


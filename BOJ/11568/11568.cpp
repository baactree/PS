// =====================================================================================
// 
//       Filename:  11568.cpp
//        Created:  2017년 03월 23일 11시 42분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> lis;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		auto it=lower_bound(lis.begin(), lis.end(), in);
		if(it==lis.end())
			lis.push_back(in);
		else
			*it=in;
	}
	printf("%d\n", lis.size());
	return 0;
}


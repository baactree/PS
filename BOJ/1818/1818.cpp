// =====================================================================================
// 
//       Filename:  1818.cpp
//        Created:  2017년 05월 19일 00시 52분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	vector<int> lis;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		auto it=upper_bound(lis.begin(), lis.end(), in);
		if(it==lis.end())
			lis.push_back(in);
		else
			*it=in;
	}
	printf("%d\n", n-lis.size());
	return 0;
}


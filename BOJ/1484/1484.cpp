// =====================================================================================
// 
//       Filename:  1484.cpp
//        Created:  2017년 09월 22일 21시 26분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int g;
int main(){
	scanf("%d", &g);
	vector<int> ans;
	for(int i=1;i<=g;i++){
		if(g%i==0){
			int right=g/i+i;
			if(right%2==0&&right/2>i)
				ans.push_back(right/2);
		}
	}
	if(ans.empty())
		return !printf("-1\n");
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for(auto x:ans)
		printf("%d\n", x);
	return 0;
}


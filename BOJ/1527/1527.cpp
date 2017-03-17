// =====================================================================================
// 
//       Filename:  1527.cpp
//        Created:  2017년 03월 17일 18시 54분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<int> t;
void solve(int idx, int pick, int now){
	if(idx==pick){
		t.push_back(now);
		return;
	}
	solve(idx+1, pick, now*10+4);
	solve(idx+1, pick, now*10+7);
}
int main(){
	scanf("%d%d", &a, &b);
	for(int i=1;i<10;i++)
		solve(0, i, 0);
	int cnt=0;
	for(int i=0;i<t.size();i++)
		if(t[i]>=a&&t[i]<=b)
			cnt++;
	printf("%d\n", cnt);
	return 0;
}


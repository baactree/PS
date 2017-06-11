// =====================================================================================
// 
//       Filename:  1436.cpp
//        Created:  2017년 06월 12일 02시 10분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void solve(int idx, int cnt, int str){
	if(idx==0){
		if(cnt==0)
			vec.push_back(str);
		return;
	}
	if(cnt>0&&idx>=3)
		solve(idx-3, cnt-1, str*1000+666);
	for(int i=0;i<10;i++)
		solve(idx-1, cnt, str*10+i);
}
int main(){
	for(int i=3;i<8;i++)
		solve(i, 1, 0);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int n;
	scanf("%d", &n);
	printf("%d\n", vec[n-1]);
	return 0;
}


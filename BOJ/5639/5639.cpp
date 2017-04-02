// =====================================================================================
// 
//       Filename:  5639.cpp
//        Created:  2017년 04월 02일 14시 15분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
void solve(int le, int ri){
	if(le>ri)
		return ;
	int idx=ri;
	for(int i=le+1;i<=ri;i++){
		if(arr[i]>arr[le]){
			idx=i-1;
			break;
		}
	}
	solve(le+1, idx);
	solve(idx+1, ri);
	printf("%d\n", arr[le]);
}
int main(){
	int in;
	while(scanf("%d", &in)!=EOF)
		arr.push_back(in);
	solve(0, (int)arr.size()-1);
	return 0;
}


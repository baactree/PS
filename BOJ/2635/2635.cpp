// =====================================================================================
// 
//       Filename:  2635.cpp
//        Created:  2017년 05월 04일 22시 54분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> ans;
int len;
vector<int> solve(int k){
	vector<int> ret=arr;
	ret.push_back(k);
	while(true){
		int now=ret[ret.size()-2]-ret[ret.size()-1];
		if(now<0)
			break;
		ret.push_back(now);
	}
	return ret;
}
int main(){
	int in;
	scanf("%d", &in);
	arr.push_back(in);
	for(int i=in/2;i<=in;i++){
		vector<int> temp=solve(i);
		if(len<temp.size()){
			len=temp.size();
			ans=temp;
		}
	}
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}


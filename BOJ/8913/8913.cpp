// =====================================================================================
// 
//       Filename:  8913.cpp
//        Created:  2017년 08월 10일 01시 42분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool ans;
void back(deque<pair<int, int> > le, deque<pair<int, int> > ri){
	if(ans)
		return;
	if(ri.empty()){
		ans=le.empty();
		return;
	}
	while(!ri.empty()){
		auto now=ri.front();
		ri.pop_front();
		if(now.second>1){
			if(!le.empty()&&!ri.empty()&&le.back().first==ri.front().first){
				auto temp=le.back();
				le.pop_back();
				ri.front().second+=temp.second;
				back(le, ri);
				ri.front().second-=temp.second;
				le.push_back(temp);
			}
			else
				back(le, ri);
		}
		le.push_back(now);
	}
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		string str;
		cin>>str;
		int col=0;
		int cnt=0;
		deque<pair<int, int> > le, ri;
		for(int i=0;i<str.size();i++){
			if(i==0||str[i-1]!=str[i]){
				col=str[i]=='a';
				cnt=1;
			}
			else
				cnt++;
			if(i+1==str.size()||str[i+1]!=str[i])
				ri.push_back({col, cnt});
		}
		ans=false;
		back(le, ri);
		printf("%d\n", ans);
	}
	return 0;
}


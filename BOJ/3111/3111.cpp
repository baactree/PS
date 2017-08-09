// =====================================================================================
// 
//       Filename:  3111.cpp
//        Created:  2017년 08월 09일 13시 12분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a, t;
deque<char> le, mid, ri;
bool possi(int mode){
	if(mode){
		for(int i=0;i<a.size();i++)
			if(mid[(int)mid.size()-1-i]!=a[(int)a.size()-1-i])
				return false;
	}
	else{
		for(int i=0;i<a.size();i++)
			if(mid[i]!=a[i])
				return false;
	}
	return true;
}
int main(){
	cin>>a>>t;
	for(int i=0;i<t.size();i++)
		mid.push_back(t[i]);
	while(true){
		bool flag=false;
		while(a.size()<=mid.size()){
			if(possi(0)){
				flag=true;
				for(int j=0;j<a.size();j++)
					mid.pop_front();
				for(int j=0;j+1<a.size()&&!le.empty();j++){
					char now=le.back();
					le.pop_back();
					mid.push_front(now);
				}
				for(int j=0;j+1<a.size()&&!ri.empty();j++){
					char now=ri.front();
					ri.pop_front();
					mid.push_back(now);
				}
				break;
			}
			else{
				char now=mid.front();
				mid.pop_front();
				le.push_back(now);
			}
		}
		if(!flag)
			break;
		flag=false;
		while(a.size()<=mid.size()){
			if(possi(1)){
				flag=true;
				for(int j=0;j<a.size();j++)
					mid.pop_back();
				for(int j=0;j+1<a.size()&&!le.empty();j++){
					char now=le.back();
					le.pop_back();
					mid.push_front(now);
				}
				for(int j=0;j+1<a.size()&&!ri.empty();j++){
					char now=ri.front();
					ri.pop_front();
					mid.push_back(now);
				}
				break;
			}
			else{
				char now=mid.back();
				mid.pop_back();
				ri.push_front(now);
			}
		}
		if(!flag)
			break;
	}
	for(int i=0;i<le.size();i++)
		printf("%c", le[i]);
	for(int i=0;i<mid.size();i++)
		printf("%c", mid[i]);
	for(int i=0;i<ri.size();i++)
		printf("%c", ri[i]);
	printf("\n");
	return 0;
}


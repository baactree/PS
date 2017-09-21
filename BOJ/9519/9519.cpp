// =====================================================================================
// 
//       Filename:  9519.cpp
//        Created:  2017년 09월 21일 19시 32분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	int x;
	cin>>x>>str;
	vector<int> now(str.size());
	for(int i=0;i<now.size();i++)
		now[i]=i;
	vector<int> st=now;
	int t=0;
	while(true){
		vector<int> next;
		int le=0;
		int ri=now.size()-1;
		while(le<=ri){
			if(le!=ri){
				next.push_back(now[le++]);
				next.push_back(now[ri--]);
			}
			else
				next.push_back(now[le++]);
		}
		now=next;
		t++;
		if(now==st)
			break;
	}
	x%=t;
	x=t-x;
	while(x--){
		string next="";
		int le=0;
		int ri=str.size()-1;
		while(le<=ri){
			if(le!=ri){
				next+=str[le++];
				next+=str[ri--];
			}
			else
				next+=str[le++];
		}
		str=next;
	}
	cout<<str<<endl;
	return 0;
}


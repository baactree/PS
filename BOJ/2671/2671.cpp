// =====================================================================================
// 
//       Filename:  2671.cpp
//        Created:  2017년 03월 29일 19시 37분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int cache[200];
int solve(int idx){
	if(idx==str.size())
		return true;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=0;
	if(idx+2<str.size()){
		if("100"==string(str.begin()+idx, str.begin()+idx+3)){
			int next=idx+3;
			while(next<str.size()&&str[next]=='0')
				next++;
			if(next==str.size())
				return ret;	
			while(next<str.size()&&str[next]=='1'){
				next++;
				ret|=solve(next);
			}
		}
	}
	if(idx+1<str.size()){
		if("01"==string(str.begin()+idx, str.begin()+idx+2)){
			int next=idx+2;
			ret|=solve(next);
			while(next+1<str.size()&&"01"==string(str.begin()+next, str.begin()+next+2)){
				next+=2;
				ret|=solve(next);
			}
		}
	}
	return ret;
}
int main(){
	cin>>str;
	memset(cache, -1, sizeof(cache));
	printf("%s\n", solve(0)?"SUBMARINE":"NOISE");
	return 0;
}


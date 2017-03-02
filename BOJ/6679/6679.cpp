// =====================================================================================
// 
//       Filename:  6679.cpp
//        Created:  2017년 03월 02일 14시 04분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
bool possi(int x){
	int a, b, c;
	a=b=c=0;
	int temp=x;
	int r=10;
	int s=1000;
	while(temp){
		a+=temp/s;
		temp%=s;
		s/=r;
	}
	temp=x;
	r=12;
	s=1728;
	while(temp){
		b+=temp/s;
		temp%=s;
		s/=r;
	}
	temp=x;
	r=16;
	s=4096;
	while(temp){
		c+=temp/s;
		temp%=s;
		s/=r;
	}

	return a==b&&b==c;
}
int main(){
	for(int i=1000;i<10000;i++)
		if(possi(i))
			ans.push_back(i);
	for(auto i:ans)
		printf("%d\n", i);
	return 0;
}


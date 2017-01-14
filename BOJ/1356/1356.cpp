// =====================================================================================
// 
//       Filename:  1356.cpp
//        Created:  2017년 01월 14일 21시 32분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int N;
bool solve(string a, string b){
	int A, B;
	A=B=1;
	for(int i=0;i<a.size();i++)
		A*=a[i]-'0';
	for(int i=0;i<b.size();i++)
		B*=b[i]-'0';
	return A==B;
}
bool possi(int n){
	string arr=to_string(n);
	for(int i=1;i<arr.size();i++)
		if(solve(string(arr.begin(), arr.begin()+i), string(arr.begin()+i, arr.end())))
			return true;
	return false;
}
int main(){
	scanf("%d", &N);
	if(possi(N))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}


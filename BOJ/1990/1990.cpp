// =====================================================================================
// 
//       Filename:  1990.cpp
//        Created:  2017년 03월 31일 17시 38분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<int> p;
bool possi(int x){
	if(x<=1)
		return false;
	if(x==2)
		return true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
void make_prime(int len, string str){
	if(len==0){
		int num=stoi(str);
		if(possi(num))
			p.push_back(num);
		return;
	}
	if(len&1){
		for(int i=0;i<10;i++)
			make_prime(len-1, to_string(i));
		return;
	}
	for(int i=0;i<10;i++){
		string temp=to_string(i)+str+to_string(i);
		make_prime(len-2, temp);
	}
}
int main(){
	for(int i=1;i<9;i++){
		make_prime(i, "");
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	scanf("%d%d", &a, &b);
	for(int i=0;i<p.size();i++)
		if(a<=p[i]&&p[i]<=b)
			printf("%d\n", p[i]);
	printf("-1\n");
	return 0;
}


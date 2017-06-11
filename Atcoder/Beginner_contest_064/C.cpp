// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 06월 10일 21시 02분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100];
set<int> s;
int cnt;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		if(in<400){
			s.insert(0);
		}
		else if(in<800){
			s.insert(1);
		}
		else if(in<1200){
			s.insert(2);
		}
		else if(in<1600){
			s.insert(3);
		}
		else if(in<2000){
			s.insert(4);
		}
		else if(in<2400){
			s.insert(5);
		}
		else if(in<2800){
			s.insert(6);
		}
		else if(in<3200){
			s.insert(7);
		}
		else{
			cnt++;
		}
	}
	printf("%d %d\n", max(1, (int)s.size()), (int)s.size()+cnt);
	return 0;
}


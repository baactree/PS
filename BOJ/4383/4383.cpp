// =====================================================================================
// 
//       Filename:  4383.cpp
//        Created:  2017년 09월 20일 21시 00분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[3000];
bool possi(){
	set<int> s;
	for(int i=1;i<n;i++){
		int now=abs(arr[i]-arr[i-1]);
		if(now<1||now>=n)
			return false;
		s.insert(now);
	}
	return s.size()==n-1;
}
int main(){
	while(scanf("%d", &n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		printf("%s\n", possi()?"Jolly":"Not jolly");
	}
	return 0;
}


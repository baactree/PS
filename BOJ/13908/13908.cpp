// =====================================================================================
// 
//       Filename:  13908.cpp
//        Created:  2017년 05월 27일 16시 57분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int check;
bool possi(int x){
	int ret=0;
	for(int i=0;i<n;i++){
		int now=x%10;
		ret|=(1<<now);
		x/=10;
	}
	return check==(check&ret);
}
int main(){
	scanf("%d%d", &n, &m);
	int r=pow(10, n);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		check|=(1<<in);
	}
	int ans=0;
	for(int i=0;i<r;i++){
		if(possi(i))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}


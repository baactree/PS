// =====================================================================================
// 
//       Filename:  11970.cpp
//        Created:  2017년 05월 26일 15시 10분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[105];
void paint(int a, int b){
	for(int i=a;i<b;i++)
		arr[i]=true;
}
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	paint(a, b);
	scanf("%d%d", &a, &b);
	paint(a, b);
	int ans=0;
	for(int i=0;i<=100;i++)
		ans+=arr[i];
	printf("%d\n", ans);
	return 0;
}


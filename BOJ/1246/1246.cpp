// =====================================================================================
// 
//       Filename:  1246.cpp
//        Created:  2017년 03월 21일 17시 57분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+m);
	int max_profit=0;
	int price;
	for(int i=0;i<m;i++){
		int now_profit=min(n, (m-i))*arr[i];
		if(max_profit<now_profit){
			max_profit=now_profit;
			price=arr[i];
		}
	}
	printf("%d %d\n",price, max_profit);
	return 0;
}


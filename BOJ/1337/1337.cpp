// =====================================================================================
// 
//       Filename:  1337.cpp
//        Created:  2017년 04월 23일 12시 00분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10000];
bool possi(int x, int y){
	for(int i=1;i<5;i++)
		if(x+i==y)
			return true;
	return false;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int ans=0x3f3f3f3f;
	for(int i=0;i<n;i++){
		int cnt=4;
		for(int j=1;j<5&&i+j<n;j++){
			if(possi(arr[i], arr[i+j]))
				cnt--;
		}
		ans=min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}


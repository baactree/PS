// =====================================================================================
// 
//       Filename:  9517.cpp
//        Created:  2017년 02월 22일 15시 26분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k, n;
pair<int, string> arr[100];
int main(){
	scanf("%d%d", &k, &n);
	for(int i=0;i<n;i++){
		int t;
		string a;
		cin>>t>>a;
		arr[i]={t, a};
	}
	k--;
	int t=0;
	for(int i=0;i<n;i++){
		t+=arr[i].first;
		if(t>=210)
			break;
		if(arr[i].second=="T")
			k=(k+1)%8;
	}
	printf("%d\n", k+1);
	return 0;
}


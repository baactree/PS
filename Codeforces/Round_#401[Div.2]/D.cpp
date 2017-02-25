// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 02월 24일 20시 11분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string arr[500000];
int calc(int idx){
	int n=arr[idx].size();
	int m=arr[idx+1].size();
	for(int i=0;i<min(n, m);i++){
		if(arr[idx][i]>arr[idx+1][i]){
			return i;
		}
	}
	return m;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=n-2;i>=0;i--){
		if(arr[i]<=arr[i+1])
			continue;
		int idx=calc(i);
		arr[i]=string(arr[i].begin(), arr[i].begin()+idx);
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<'\n';
	return 0;
}


// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 07월 31일 23시 38분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k;
string n;
int arr[100005];
int main(){
	cin>>k>>n;
	int sum=0;
	for(int i=0;i<n.size();i++){
		sum+=n[i]-'0';
		arr[i]=n[i]-'0';
	}
	int len=n.size();
	sort(arr, arr+len);
	int ans=0;
	for(int i=0;i<len;i++){
		if(sum>=k)
			break;
		sum+=9-arr[i];
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}


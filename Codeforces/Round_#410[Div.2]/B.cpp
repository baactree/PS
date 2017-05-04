// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 05월 04일 10시 15분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string arr[50];
int m[50];
string h;
int n;
void possi(){
	for(int i=1;i<n;i++)
		if(arr[i].find(h)==string::npos)
			m[i]=-1;
		else
			m[i]=arr[i].find(h);
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i==0)
			h=arr[i];
		arr[i]+=arr[i];
	}
	possi();
	for(int i=0;i<n;i++)
		if(m[i]==-1){
			printf("-1\n");
			return 0;
		}
	int ans=0x3f3f3f3f;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			cnt+=arr[j].find(string(arr[i].begin(), arr[i].begin()+h.size()));
		}
		ans=min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}


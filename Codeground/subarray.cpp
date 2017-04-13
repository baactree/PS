// =====================================================================================
// 
//       Filename:  subarray.cpp
//        Created:  2017년 04월 13일 00시 30분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, s;
int arr[100000];
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		scanf("%d%d", &n, &s);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		int st, fi;
		st=fi=0;
		int sum=0;
		int ans=0x3f3f3f3f;
		while(st<=fi&&st<n){
			if(sum>=s){
				ans=min(ans, fi-st);
				sum-=arr[st];
				st++;
			}
			else if(fi<n){
				sum+=arr[fi];
				fi++;
			}
			else
				break;

		}
		printf("#testcase%d\n%d\n", tc, ans==0x3f3f3f3f?0:ans);
	}
	return 0;
}


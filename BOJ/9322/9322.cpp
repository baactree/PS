// =====================================================================================
// 
//       Filename:  9322.cpp
//        Created:  2017년 04월 28일 16시 03분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string arr[1000];
string out[1000];
int perm[1000];
int n;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++){
			string temp;
			cin>>temp;
			for(int j=0;j<n;j++)
				if(temp==arr[j])
					perm[j]=i;
		}
		for(int i=0;i<n;i++)
			cin>>out[i];
		for(int i=0;i<n;i++)
			cout<<out[perm[i]]<<" ";
		printf("\n");
	}
	return 0;
}


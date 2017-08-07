// =====================================================================================
// 
//       Filename:  12033.cpp
//        Created:  2017년 08월 04일 23시 34분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[10];
int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int tc=1;tc<=testcase;tc++){
		scanf("%d", &n);
		for(int i=0;i<2*n;i++)
			scanf("%d", &arr[i]);
		do{
			bool flag=true;
			for(int i=0;i<n;i++){
				if(arr[i+n]%4==0&&arr[i+n]/4*3==arr[i])
					continue;
				flag=false;
			}
			if(flag)
				goto p;
		}while(next_permutation(arr, arr+n*2));
p:
		sort(arr, arr+n);
		printf("Case #%d:", tc);
		for(int i=0;i<n;i++)
			printf(" %d", arr[i]);
		printf("\n");
	}
	return 0;
}


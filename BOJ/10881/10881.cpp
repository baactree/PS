// =====================================================================================
// 
//       Filename:  10881.cpp
//        Created:  2017년 05월 16일 20시 28분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[3][2];
int perm[3];
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		for(int i=0;i<3;i++){
			scanf("%d%d", &arr[i][0], &arr[i][1]);
			perm[i]=i;
		}
		int ans=0x3f3f3f3f;
		do{
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					for(int k=0;k<2;k++){
						ans=min(ans, (arr[perm[0]][i]+arr[perm[1]][j]+arr[perm[2]][k])*(max(arr[perm[0]][1-i], max(arr[perm[1]][1-j], arr[perm[2]][1-k]))));
						ans=min(ans, (arr[perm[0]][i]+max(arr[perm[1]][j], arr[perm[2]][k]))*(max(arr[perm[0]][1-i], arr[perm[1]][1-j]+arr[perm[2]][1-k])));
					}
		}while(next_permutation(perm, perm+3));
		printf("%d\n", ans);
	}
	return 0;
}


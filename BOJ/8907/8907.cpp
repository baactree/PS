// =====================================================================================
// 
//       Filename:  8907.cpp
//        Created:  2017년 09월 22일 20시 50분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[1005][1005];
int a[1005], b[1005];
int n;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		memset(mat, 0, sizeof(mat));
		scanf("%d", &n);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				scanf("%d", &mat[i][j]);
				mat[j][i]=mat[i][j];
			}
		int ans=n*(n-1)*(n-2)/6;
		
		for(int i=1;i<=n;i++){
			a[i]=b[i]=0;
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				if(mat[i][j])
					a[i]++;
				else
					b[i]++;
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i]*b[i];
		}
		printf("%d\n", ans-sum/2);
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  newroom.cpp
//        Created:  2017년 04월 09일 19시 05분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int mat[100][100];
pair<int, int> arr[100][100];
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%d", &mat[i][j]);
				int a, b;
				a=b=0;
				//3의 개수를 센다
				while(mat[i][j]%3==0){
					a++;
					mat[i][j]/=3;
				}
				//2의 개수를 센다
				while(mat[i][j]%2==0){
					b++;
					mat[i][j]/=2;
				}
				arr[i][j]={b, a};
			}
		map<int, int> dp[100][100];
		//초기값 설정
		dp[0][0][arr[0][0].second]=arr[0][0].first;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				//i행 j열에 저장된 모든 k 값에 대해서
				for(auto it=dp[i][j].begin();it!=dp[i][j].end();it++){
					int k=(*it).first;
					int q=(*it).second;
					if(j!=n-1)
						dp[i][j+1][k+arr[i][j+1].second]=max(dp[i][j+1][k+arr[i][j+1].second], q+arr[i][j+1].first);
					if(i!=n-1)
						dp[i+1][j][k+arr[i+1][j].second]=max(dp[i+1][j][k+arr[i+1][j].second], q+arr[i+1][j].first);
				}
		int ans=0;
		//n-1행 n-1열에 저장된 모든 3의 개수에 대해서
		for(auto it=dp[n-1][n-1].begin();it!=dp[n-1][n-1].end();it++){
			int a=(*it).first;
			int b=(*it).second;
			ans=max(ans, min(a, b));
		}
		printf("Case #%d\n%d\n", tc, ans);
	}
	return 0;
}


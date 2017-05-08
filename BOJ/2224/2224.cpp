// =====================================================================================
// 
//       Filename:  2224.cpp
//        Created:  2017년 05월 08일 19시 30분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[300][300];
int n;
vector<pair<int, int> > ans;
int main(){
	memset(mat, 0x3f, sizeof(mat));
	scanf("%d\n", &n);
	for(int i=0;i<n;i++){
		string input;
		getline(cin, input);
		mat[input[0]][input[5]]=1;
	}
	for(int k=0;k<300;k++)
		for(int i=0;i<300;i++)
			for(int j=0;j<300;j++)
				mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
	for(int i=0;i<300;i++)
		for(int j=0;j<300;j++){
			if(i==j)continue;
			if(mat[i][j]!=0x3f3f3f3f)
				ans.push_back({i, j});
		}
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%c => %c\n", ans[i].first, ans[i].second);
	return 0;
}


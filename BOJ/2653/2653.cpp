// =====================================================================================
// 
//       Filename:  2653.cpp
//        Created:  2017년 06월 14일 02시 05분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int mat[100][100];
bool trip[100];
vector<vector<int> > ans;
void f(){
	printf("0\n");
	exit(0);
}
bool check(const vector<int> &vec){
	for(int i=0;i<vec.size();i++){
		int now=vec[i];
		vector<int> temp;
		for(int j=0;j<n;j++){
			if(mat[now][j]==0)
				temp.push_back(j);
		}
		if(vec.size()!=temp.size())
			return false;
		for(int j=0;j<vec.size();j++)
			if(vec[j]!=temp[j])
				return false;
	}
	return true;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &mat[i][j]);
	for(int i=0;i<n;i++){
		if(!trip[i]){
			vector<int> vec;
			for(int j=0;j<n;j++)
				if(mat[i][j]==0)
					vec.push_back(j);
			if(vec.size()==1)
				f();
			if(!check(vec))
				f();
			for(int j=0;j<vec.size();j++)
				trip[vec[j]]=true;
			ans.push_back(vec);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++)
			printf("%d ", ans[i][j]+1);
		printf("\n");
	}
	return 0;
}


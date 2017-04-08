// =====================================================================================
// 
//       Filename:  12100.cpp
//        Created:  2017년 04월 05일 18시 57분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int mat[20][20];
// idx = 현재 깊이
int solve(int idx){
	// 깊이가 5인 경우
	if(idx==5){
		int ret=0;
		// 블록중에 최대 블록을 찾음
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ret=max(ret, mat[i][j]);
		return ret;
	}
	int ret=0;
	//상하좌우 4방향에 대해서 0좌1우2상3하
	for(int i=0;i<4;i++){
		//현재 상태 공간을 저장
		int temp[20][20];
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				temp[j][k]=mat[j][k];
		//q행(또는 열)에 대해서 블록을 저장하고 합침
		for(int q=0;q<n;q++){
			//방향이 세로인 경우 행과 열을 뒤집음
			//방향이 1또는 3인경우 순서를 뒤집음
			vector<int> temp;
			for(int p=0;p<n;p++)
				if((i<2?mat[q][p]:mat[p][q])!=0)
					temp.push_back(i<2?mat[q][p]:mat[p][q]);
			if(i==1||i==3)
				reverse(temp.begin(), temp.end());
			vector<int> perm;
			for(int p=0;p<temp.size();p++)
				if(p+1<temp.size()&&temp[p]==temp[p+1]){
					perm.push_back(temp[p]*2);
					p++;
				}
				else
					perm.push_back(temp[p]);
			for(int p=perm.size();p<n;p++)
				perm.push_back(0);
			if(i==1||i==3)
				reverse(perm.begin(), perm.end());
			for(int p=0;p<n;p++)
				(i<2?mat[q][p]:mat[p][q])=perm[p];
		}	
		//다음 상태 공간으로 전이
		ret=max(ret, solve(idx+1));
		//원래 상태 공간 복구
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				mat[j][k]=temp[j][k];
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &mat[i][j]);
	printf("%d\n", solve(0));
	return 0;
}


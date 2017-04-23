// =====================================================================================
// 
//       Filename:  6987.cpp
//        Created:  2017년 04월 21일 17시 41분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[6][3];
bool solve(int idx, int nidx){
	if(idx==6){
		int cnt=0;
		for(int i=0;i<6;i++)
			for(int j=0;j<3;j++)
				cnt+=arr[i][j];
		return cnt==0;
	}
	if(nidx>=6)
		return solve(idx+1, idx+2);
	bool ret=false;
	if(arr[idx][0]>0&&arr[nidx][2]>0){
		arr[idx][0]--;
		arr[nidx][2]--;
		ret|=solve(idx, nidx+1);
		arr[idx][0]++;
		arr[nidx][2]++;
	}
	if(arr[idx][1]>0&&arr[nidx][1]>0){
		arr[idx][1]--;
		arr[nidx][1]--;
		ret|=solve(idx, nidx+1);
		arr[idx][1]++;
		arr[nidx][1]++;
	}
	if(arr[idx][2]>0&&arr[nidx][0]>0){
		arr[idx][2]--;
		arr[nidx][0]--;
		ret|=solve(idx, nidx+1);
		arr[idx][2]++;
		arr[nidx][0]++;
	}
	return ret;
}
int main(){
	int TestCase=4;
	while(TestCase--){
		for(int i=0;i<6;i++)
			for(int j=0;j<3;j++)
				scanf("%d", &arr[i][j]);
		printf("%d ", solve(0, 1));
	}
	return 0;
}


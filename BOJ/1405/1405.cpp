// =====================================================================================
// 
//       Filename:  1405.cpp
//        Created:  2017년 03월 03일 13시 10분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[4];
bool check[30][30];
double solve(int idx, int x, int y){
	if(check[x+15][y+15])
		return 0;
	if(idx==n)
		return 1;
	check[x+15][y+15]=true;
	double ret=solve(idx+1, x+1, y)*(arr[0]/100.);
	ret+=solve(idx+1, x-1, y)*(arr[1]/100.);
	ret+=solve(idx+1, x, y+1)*(arr[2]/100.);
	ret+=solve(idx+1, x, y-1)*(arr[3]/100.);
	
	check[x+15][y+15]=false;
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<4;i++)
		scanf("%d", &arr[i]);
	printf("%.10lf\n", solve(0, 0, 0));
	return 0;
}


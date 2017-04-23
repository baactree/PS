// =====================================================================================
// 
//       Filename:  3933.cpp
//        Created:  2017년 04월 21일 12시 09분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> p;
int pick[4];
int solve(int x, int k, int idx){
	if(x<=0)
		return 0;
	if(k<0)
		return 0;
	if(idx==p.size()){
		if(x>0&&k==0){
			int temp=sqrt(x);
			if(temp==sqrt(x)){
				return temp>=pick[1];
			}
			return 0;
		}
		return 0;
	}
	int ret=0;
	ret+=solve(x, k, idx+1);
	if(k>0){
		pick[k]=p[idx];
		ret+=solve(x-p[idx]*p[idx], k-1, idx);
	}
	return ret;
}	
int main(){
	for(int i=0;i<1<<8;i++)
		p.push_back(i);
	while(true){
		int n;
		scanf("%d", &n);
		if(n==0)
			break;
		printf("%d\n", solve(n, 3, 0));
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  1062.cpp
//        Created:  2017년 03월 21일 19시 02분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
string arr[50];
bool possi(int idx, int state){
	for(int i=4;i<arr[idx].size()-4;i++)
		if(!((1<<(arr[idx][i]-'a')&state)))
			return false;
	return true;
}
int solve(int idx, int c, int state){
	if(c>k)
		return 0;
	if(idx==26){
		int cnt=0;
		for(int i=0;i<n;i++)
			if(possi(i, state))
				cnt++;
		return cnt;
	}
	if(idx+'a'=='a'||idx+'a'=='n'||idx+'a'=='t'||idx+'a'=='i'||idx+'a'=='c')
		return solve(idx+1, c+1, state|(1<<idx));
	int ret2=solve(idx+1, c+1, state|(1<<idx));
	int ret=solve(idx+1, c, state);
	ret=max(ret, ret2);
	return ret;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	printf("%d\n", solve(0, 0, 0));
	return 0;
}


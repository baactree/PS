// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 06월 27일 23시 28분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b, l, r;
bool used[50];
int pick[105];
vector<int> vec;
int main(){
	scanf("%d%d%d%d", &a, &b, &l, &r);
	l--;
	r--;
	r=min(l+100, r);
	for(int i=0;i<a;i++)
		pick[i]=i;
	for(int i=a;i<a+b;i++)
		pick[i]=pick[i-1];
	for(int i=b;i<a+b;i++)
		used[pick[i]]=true;
	for(int i=0;i<26;i++)
		if(!used[i])
			vec.push_back(i);
	for(int i=0;i<a;i++)
		pick[i+a+b]=vec[i];
	for(int i=a;i<a+b;i++)
		pick[i+a+b]=pick[i-1+a+b];

	memset(used, 0, sizeof(used));
	for(int i=l;i<=r;i++)
		used[pick[i%(2*(a+b))]]=true;
	int ans=0;
	for(int i=0;i<26;i++)
		if(used[i])
			ans++;
	printf("%d\n", ans);
	return 0;
}

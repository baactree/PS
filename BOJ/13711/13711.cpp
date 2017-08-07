// =====================================================================================
// 
//       Filename:  13711.cpp
//        Created:  2017년 08월 08일 01시 38분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int ra[100005];
int b[100005];
int c[100005];
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		ra[x]=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d", &b[i]);
	for(int i=1;i<=n;i++)
		c[i]=ra[b[i]];
	vector<int> lis;
	for(int i=1;i<=n;i++){
		auto it=lower_bound(lis.begin(), lis.end(), c[i]);
		if(it==lis.end())
			lis.push_back(c[i]);
		else
			*it=c[i];
	}
	cout<<lis.size()<<endl;
	return 0;
}


// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 08일 03시 40분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int m;
int a[200000];
pair<int, int> b[200000];
int ans[200000];
int main(){
	scanf("%d", &m);
	for(int i=0;i<m;i++)
		scanf("%d", &a[i]);
	for(int i=0;i<m;i++){
		scanf("%d", &b[i].first);
		b[i].second=i;
	}
	sort(b, b+m);
	sort(a, a+m);
	for(int i=0;i<m;i++){
		ans[b[i].second]=a[m-1-i];
	}
	for(int i=0;i<m;i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}


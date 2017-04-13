// =====================================================================================
// 
//       Filename:  1838.cpp
//        Created:  2017-04-12 ¿ÀÈÄ 1:20:37
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int a[500000];
int b[500000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
		b[i]=a[i];			
	}
	sort(a, a+n);
	int ans=0;
	for(int i=0;i<n;i++){
		int idx=lower_bound(a, a+n, b[i])-a;
		ans=max(ans, max(0, i-idx));
	}
	printf("%d\n", ans);
	return 0;
}


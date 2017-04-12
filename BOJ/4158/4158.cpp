// =====================================================================================
// 
//       Filename:  4158.cpp
//        Created:  2017-04-12 ¿ÀÈÄ 12:28:43
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[1000000];
int n, m;
int main(){
	while(true){
		scanf("%d%d", &n, &m);
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n);
		int ans=0;
		for(int i=0;i<m;i++){
			int in;
			scanf("%d", &in);
			pair<int *, int *> temp=equal_range(arr, arr+n, in);
			ans+=temp.second-temp.first;
		}
		printf("%d\n", ans);
	}return 0;
}


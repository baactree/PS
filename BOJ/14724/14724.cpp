// =====================================================================================
// 
//       Filename:  14724.cpp
//        Created:  2017년 09월 21일 09시 21분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string arr[9]={"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
int main(){
	scanf("%d", &n);
	int idx;
	int ans=0;
	for(int i=0;i<9;i++){
		int max_value=0;
		for(int j=0;j<n;j++){
			int x;
			scanf("%d", &x);
			max_value=max(x, max_value);
		}
		if(ans<max_value){
			ans=max_value;
			idx=i;
		}
	}
	cout<<arr[idx]<<endl;
	return 0;
}


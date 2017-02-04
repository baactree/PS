// =====================================================================================
// 
//       Filename:  11866.cpp
//        Created:  2017년 02월 04일 21시 50분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[1000];
bool trip[1000];
int N, M;
int main(){
	scanf("%d%d", &N, &M);
	vector<int> ans;
	int now=0;
	int n=N;
	while(N--){
		int k=M-1+trip[now];
		while(k--){
			if(trip[(now+1)%n])
				k++;
			now++;
			now%=n;
		}
		ans.push_back(now+1);
		trip[now]=true;
	}
	printf("<");
	for(int i=0;i<ans.size();i++){
		if(i!=0)
			printf(", ");
		printf("%d", ans[i]);
	}
	printf(">");
	return 0;
}


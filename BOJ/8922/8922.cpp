// =====================================================================================
// 
//       Filename:  8922.cpp
//        Created:  2017년 09월 14일 18시 15분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int n;
		scanf("%d", &n);
		set<vector<int> > s;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			scanf("%d", &vec[i]);
		int ans=-1;
		while(true){
			int sum=0;
			for(int i=0;i<n;i++)
				sum+=vec[i];
			if(sum==0){
				ans=1;
				break;
			}
			if(s.find(vec)!=s.end()){
				ans=2;
				break;
			}
			s.insert(vec);
			vector<int> nvec(n);
			for(int i=0;i<n;i++)
				nvec[i]=abs(vec[i]-vec[(i+1)%n]);
			vec=nvec;
		}
		printf("%s\n", ans==1?"ZERO":"LOOP");
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  9339.cpp
//        Created:  2017년 04월 23일 19시 01분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k, n;
set<int> s;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		s.clear();
		scanf("%d", &k);
		for(int i=0;i<k;i++){
			int in;
			scanf("%d", &in);
			s.insert(in);
		}
		int ans=0;
		int min_value=0x3f3f3f3f;
		int min_ans;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if(s.find(a)==s.end())
				continue;
			if(b==-1||c==-1)
				continue;
			int t=b*60+c;
			if(t<=360){
				ans++;
				if(t<min_value){
					min_ans=a;
					min_value=t;
				}
			}
		}
		printf("%d %d\n", min_ans, ans);
	}
	return 0;
}


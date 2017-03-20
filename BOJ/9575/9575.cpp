// =====================================================================================
// 
//       Filename:  9575.cpp
//        Created:  2017년 03월 20일 19시 46분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a[50];
int b[50];
int c[50];
bool possi(int x){
	string now=to_string(x);
	for(int i=0;i<now.size();i++)
		if(now[i]!='8'&&now[i]!='5')
			return false;
	return true;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int k, l, m;
		scanf("%d", &k);
		for(int i=0;i<k;i++)
			scanf("%d", &a[i]);
		scanf("%d", &l);
		for(int i=0;i<l;i++)
			scanf("%d", &b[i]);
		scanf("%d", &m);
		for(int i=0;i<m;i++)
			scanf("%d", &c[i]);
		int cnt=0;
		set<int> s;
		for(int i=0;i<k;i++)
			for(int j=0;j<l;j++)
				for(int q=0;q<m;q++){
					int now=a[i]+b[j]+c[q];
					if(possi(now)&&s.find(now)==s.end()){
						cnt++;
						s.insert(now);
					}
				}
		printf("%d\n", cnt);
	}
	return 0;
}


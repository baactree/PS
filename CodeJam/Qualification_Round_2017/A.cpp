// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 04월 08일 13시 38분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-l.in", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for(int t=1;t<=tc;t++){
		string str;
		int k;
		cin>>str>>k;
		int ans=0;
		for(int i=0;i+k<=str.size();i++){
			if(str[i]=='-'){
				ans++;
				for(int j=i;j<i+k;j++)
					if(str[j]=='-')
						str[j]='+';
					else
						str[j]='-';
			}
		}
		printf("Case #%d: ", t);
		if(str==string(str.size(), '+'))
			printf("%d\n", ans);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}


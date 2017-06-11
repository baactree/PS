// =====================================================================================
// 
//       Filename:  2037.cpp
//        Created:  2017년 06월 12일 02시 00분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int p, w;
string str;
pair<int, int> g[300];
int main(){
	scanf("%d %d\n", &p, &w);
	getline(cin, str);
	int ans=0;
	int pre=-1;
	g['A']={2, 1};
	g['B']={2, 2};
	g['C']={2, 3};
	g['D']={3, 1};
	g['E']={3, 2};
	g['F']={3, 3};
	g['G']={4, 1};
	g['H']={4, 2};
	g['I']={4, 3};
	g['J']={5, 1};
	g['K']={5, 2};
	g['L']={5, 3};
	g['M']={6, 1};
	g['N']={6, 2};
	g['O']={6, 3};
	g['P']={7, 1};
	g['Q']={7, 2};
	g['R']={7, 3};
	g['S']={7, 4};
	g['T']={8, 1};
	g['U']={8, 2};
	g['V']={8, 3};
	g['W']={9, 1};
	g['X']={9, 2};
	g['Y']={9, 3};
	g['Z']={9, 4};
	g[' ']={1, 1};
	for(int i=0;i<str.size();i++){
		if(str[i]==' '){
			ans+=p;
			pre=-1;
			continue;
		}
		int now=g[str[i]].first;
		if(now==pre)
			ans+=w;
		ans+=g[str[i]].second*p;
		pre=now;
	}
	printf("%d\n", ans);
	return 0;
}


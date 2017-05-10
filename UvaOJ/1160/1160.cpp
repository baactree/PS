// =====================================================================================
// 
//       Filename:  1160.cpp
//        Created:  2017년 05월 02일 19시 54분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b;
int par[100005];
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	par[x]=y;
}
int main(){
	while(scanf("%d", &a)!=EOF){
		if(a==-1)
			continue;
		for(int i=0;i<100005;i++)
			par[i]=i;
		scanf("%d", &b);
		merge(a, b);
		int ans=0;
		while(true){
			scanf("%d", &a);
			if(a==-1)
				break;
			scanf("%d", &b);
			if(find(a)==find(b))
				ans++;
			else
				merge(a, b);
		}
		printf("%d\n", ans);
	}
	return 0;
}


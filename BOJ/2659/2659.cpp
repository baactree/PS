// =====================================================================================
// 
//       Filename:  2659.cpp
//        Created:  2017년 03월 15일 21시 58분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int mkt(int a,int b,int c,int d){
	vector<int> temp;
	temp.push_back(a*1000+b*100+c*10+d);
	temp.push_back(b*1000+c*100+d*10+a);
	temp.push_back(c*1000+d*100+a*10+b);
	temp.push_back(d*1000+a*100+b*10+c);
	sort(temp.begin(), temp.end());
	return temp[0];
}
int main(){
	for(int a=1;a<=9;a++)
		for(int b=1;b<=9;b++)
			for(int c=1;c<=9;c++)
				for(int d=1;d<=9;d++){
					int now=mkt(a, b, c, d);
					t.push_back(now);
				}
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()),t.end()); 
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int now=mkt(a, b, c, d);
	int idx=find(t.begin(), t.end(), now)-t.begin()+1;
	printf("%d\n", idx);
	return 0;
}


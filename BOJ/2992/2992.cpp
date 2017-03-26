// =====================================================================================
// 
//       Filename:  2992.cpp
//        Created:  2017년 03월 26일 18시 52분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	scanf("%d", &x);
	string temp=to_string(x);
	vector<int> vec;
	for(int i=0;i<temp.size();i++)
		vec.push_back(temp[i]-'0');
	sort(vec.begin(), vec.end());
	do{
		int t=0;
		for(int i=0;i<vec.size();i++)
			t=t*10+vec[i];
		if(t>x){
			printf("%d\n", t);
			return 0;
		}
	}while(next_permutation(vec.begin(), vec.end()));
	printf("0\n");
	return 0;
}


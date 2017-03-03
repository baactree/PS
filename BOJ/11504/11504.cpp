// =====================================================================================
// 
//       Filename:  11504.cpp
//        Created:  2017년 03월 01일 13시 25분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n, m;
		string x, y, arr;
		scanf("%d%d", &n, &m);
		for(int i=0;i<m;i++){
			int in;
			scanf("%d", &in);
			x.push_back((char)(in+'0'));
		}
		for(int i=0;i<m;i++){
			int in;
			scanf("%d", &in);
			y.push_back((char)(in+'0'));
		}
		for(int i=0;i<n;i++){
			int in;
			scanf("%d", &in);
			arr.push_back((char)(in+'0'));
		}
		arr=arr+arr;
		int ans=0;
		for(int i=0;i<n;i++){
			string temp=string(arr.begin()+i, arr.begin()+i+m);
			if(x<=temp&&temp<=y)
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}


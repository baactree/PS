
// =====================================================================================
// 
//       Filename:  14002.cpp
//        Created:  2017년 03월 22일 19시 23분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> lis;
	int d[1000005];
	int a[1000005];
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		a[i]=in;
		auto it = lower_bound(lis.begin(), lis.end(), in);
		if(it==lis.end()){
			lis.push_back(in);
			d[i]=lis.size();
		}
		else{
			*it=in;
			d[i]=it-lis.begin()+1;
		}
	}
	stack<int> st;
	cout<<lis.size()<<endl;
	int now=lis.size();
	for(int i=n-1;i>=0;i--){
		if(now==d[i]){
			st.push(a[i]);
			now--;
		}
	}
	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
	return 0;
}


// =====================================================================================
// 
//       Filename:  1327.cpp
//        Created:  2017년 05월 22일 16시 40분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
map<string, int> mp;
string goal="";
int main(){
	scanf("%d%d", &n, &k);
	string str="";
	for(int i=0;i<n;i++){
		goal+=(char)(i+'0'+1);
		int in;
		scanf("%d", &in);
		str+=(char)(in+'0');
	}
	queue<string> q;
	q.push(str);
	mp[str]=0;
	while(!q.empty()){
		string now=q.front();
		q.pop();
		for(int i=0;i+k<=n;i++){
			string there=now;
			reverse(there.begin()+i, there.begin()+i+k);
			if(mp.count(there)==0){
				mp[there]=mp[now]+1;
				q.push(there);
			}
		}
	}
	printf("%d\n", mp.count(goal)==0?-1:mp[goal]);
	return 0;
}


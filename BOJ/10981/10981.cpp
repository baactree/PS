// =====================================================================================
// 
//       Filename:  10981.cpp
//        Created:  2017년 06월 03일 23시 09분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Team{
	char school[35], name[35];
	int n, p;
	bool operator < (const Team &rhs)const{
		if(n==rhs.n)
			return p<rhs.p;
		return n>rhs.n;
	}
};
int n, k;
Team arr[100000];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%s%s%d%d", arr[i].school, arr[i].name, &arr[i].n, &arr[i].p);
	}
	sort(arr, arr+n);
	set<string> s;
	int cnt=0;
	for(int i=0;i<n;i++){
		string school=arr[i].school;
		if(s.find(school)!=s.end())
			continue;
		s.insert(school);
		printf("%s\n", arr[i].name);
		cnt++;
		if(cnt==k)
			break;
	}
	return 0;
}


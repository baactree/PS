// =====================================================================================
// 
//       Filename:  11946.cpp
//        Created:  2017년 04월 23일 20시 02분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int num, cnt, t;
	bool operator < (const Node &rhs)const{
		if(cnt==rhs.cnt){
			if(t==rhs.t){
				return num<rhs.num;
			}
			return t<rhs.t;
		}
		return cnt>rhs.cnt;
	}
};
int n, m, q;
int cnt[101][16];
bool pass[101][16];
Node arr[101];
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=n;i++)
		arr[i].num=i;
	for(int i=0;i<q;i++){
		int z, a, b;
		char c[10];
		scanf("%d%d%d%s", &z, &a, &b, c);
		if(pass[a][b])
			continue;
		if(c[0]=='A'){
			arr[a].cnt++;
			arr[a].t+=cnt[a][b]*20+z;
			pass[a][b]=true;
		}
		else {
			cnt[a][b]++;
		}
	}
	sort(arr+1, arr+n+1);
	for(int i=1;i<=n;i++)
		printf("%d %d %d\n", arr[i].num, arr[i].cnt, arr[i].t);
	return 0;
}


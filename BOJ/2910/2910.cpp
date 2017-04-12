// =====================================================================================
// 
//       Filename:  2910.cpp
//        Created:  2017-04-12 ¿ÀÈÄ 1:51:16
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int val, idx, cnt;
	Node():val(0), idx(0x3f3f3f3f), cnt(0){}
	bool operator < (const Node &rhs)const{
		if(cnt==rhs.cnt)
			return idx<rhs.idx;
		return cnt>rhs.cnt;
	}
};
Node arr[1000];
int n, c;
int main(){
	scanf("%d%d", &n, &c);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i].val);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(arr[i].val==arr[j].val){
				arr[i].cnt++;
				arr[i].idx=min(arr[i].idx, j);
			}
	sort(arr, arr+n);
	for(int i=0;i<n;i++)
		printf("%d ", arr[i].val);
	printf("\n");
	return 0;
}


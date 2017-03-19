// =====================================================================================
// 
//       Filename:  1168.cpp
//        Created:  2017년 03월 19일 20시 14분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int tree[100001];
void update(int idx, int val){
	while(idx<=100000){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	while(idx>0){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int n, m;
bool possi(int x, int st, int k, int cnt){
	if(x>st)
		return query(x)-query(st)>=k;
	return cnt-query(st)+query(x)>=k;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		update(i, 1);
	int now=0;
	printf("<");
	while(true){
		int cnt=query(n);
		int k=(m-1)%cnt+1;
		int le, ri, mid;
		le=1;ri=n;
		int next;
		while(le<=ri){
			mid=(le+ri)/2;
			int xmid=(now+mid-1)%n+1;
			if(possi(xmid, now, k, cnt)){
				next=xmid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		printf("%d", next);
		update(next, -1);
		now=next;
		if(cnt>1)
			printf(", ");
		else
			break;
	}
	printf(">\n");
	return 0;
}


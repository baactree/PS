// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 14일 19시 56분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int tree[200005];
int lcnt, rcnt;
void update(int idx, int val){
	while(idx<200005){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int find(int le, int ri, int x){
	int ret=-1;
	while(le<=ri){
		int mid=(le+ri)/2;
		if(query(mid)<=x){
			ret=mid;
			le=mid+1;
		}
		else
			ri=mid-1;
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		update(i, 1);
	int mid=n/2+1;
	vector<pair<int, int> > q(m);
	bool flag=false;
	for(int i=0;i<m;i++){
		scanf("%d%d", &q[i].first, &q[i].second);
		if(!flag&&q[i].first==1){
			if(q[i].second<=n/2)
				mid=n/2+1;
			else
				mid=n/2;
			flag=true;
		}
	}
	if(n%2==0)
		mid=n/2;
	for(int i=0;i<m;i++){
		int a, b;
		a=q[i].first;
		b=q[i].second;
		if(a==1){
			if(b<=mid){
				update(b+1, -1);
				update(mid+1, 1);
				lcnt++;
			}
			else{
				update(mid+1, 1);
				update(b+1, -1);
				rcnt++;
			}
		}
		else{
			if(b<=mid){
				if(b>mid-lcnt){
					printf("0\n");
				}
				else
					printf("%d\n", find(1, mid, b));
			}
			else{
				if(b<=mid+rcnt){
					printf("0\n");
				}
				else
					printf("%d\n", find(mid+1, n, b));
			}
		}
	}
	return 0;
}


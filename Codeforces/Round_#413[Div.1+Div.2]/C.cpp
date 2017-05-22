// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 05월 22일 23시 23분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, c, d;
vector<pair<int, int> > D;
vector<pair<int, int> > C;
const int inf=0x3f3f3f3f;
int tree[400000];
int sz;
void update(int idx, int val){
	idx+=sz;
	while(idx){
		tree[idx]=max(tree[idx], val);
		idx/=2;
	}
}
int query(int a, int b){
	int ret=0;
	a+=sz;
	b+=sz;
	while(a<=b){
		if(a&1){
			ret=max(tree[a], ret);
			a++;
		}
		if(!(b&1)){
			ret=max(tree[b], ret);
			b--;
		}
		a/=2;
		b/=2;
	}
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &c, &d);
	for(int i=0;i<n;i++){
		int a, b;
		char t;
		scanf("%d %d %c", &a, &b, &t);
		if(t=='C'){
			C.push_back({b, a});
		}
		else{
			D.push_back({b, a});
		}
	}
	sort(C.begin(), C.end());
	sort(D.begin(), D.end());
	int ans=0;
	//case 1
	int a, b;
	a=b=0;
	for(int i=0;i<C.size();i++)
		if(C[i].first<=c)
			a=max(a, C[i].second);
	for(int i=0;i<D.size();i++)
		if(D[i].first<=d)
			b=max(b, D[i].second);
	if(a!=0&&b!=0)
		ans=max(ans, a+b);
	//case 2
	reverse(C.begin(), C.end());
	memset(tree, 0, sizeof(tree));
	sz=1;
	while(sz<C.size())
		sz*=2;
	for(int i=0;i<C.size();i++){
		update(i, C[i].second);
	}
	for(int i=0;i<C.size();i++){
		int b=(int)C.size()-1;
		int le, ri, mid, a;
		a=C.size();
		le=i+1;
		ri=b;
		while(le<=ri){
			mid=(le+ri)/2;
			if(C[mid].first<=c-C[i].first){
				a=mid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		if(a>b)
			continue;
		ans=max(C[i].second+query(a, b), ans);
	}
	//case 3
	reverse(D.begin(), D.end());
	memset(tree, 0, sizeof(tree));
	sz=1;
	while(sz<D.size())
		sz*=2;
	for(int i=0;i<D.size();i++){
		update(i, D[i].second);
	}
	for(int i=0;i<D.size();i++){
		int b=(int)D.size()-1;
		int le, ri, mid, a;
		a=D.size();
		le=i+1;
		ri=b;
		while(le<=ri){
			mid=(le+ri)/2;
			if(D[mid].first<=d-D[i].first){
				a=mid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		if(a>b)
			continue;
		ans=max(D[i].second+query(a, b), ans);
	}
	printf("%d\n", ans);
	return 0;
}

